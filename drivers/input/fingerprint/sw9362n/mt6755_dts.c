#include "finger.h"
#include "config.h"
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/of_irq.h>
#include <linux/completion.h>
#include <linux/delay.h>

#ifdef CONFIG_OF
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#endif
#include <mt_spi.h>

#ifdef _DRV_TAG_
#undef _DRV_TAG_
#endif
#define _DRV_TAG_ "mt6755_dts"

//------------------------------------------------------------------------------


/**
 * this function olny use thread ex.open
 *
 */

typedef enum DTS_STATE {
    STATE_CS_CLR,
    STATE_CS_SET,
    STATE_MI_CLR,
    STATE_MI_SET,
    STATE_MO_CLR,
    STATE_MO_SET,
    STATE_CLK_CLR,
    STATE_CLK_SET,
    STATE_RST_CLR,
    STATE_RST_SET,
    STATE_EINT,
	STATE_POWER_SET,
    STATE_POWER_CLR,
    STATE_EINT_CLR,
    STATE_EINT_SET,
    STATE_MAX,  /* array size */
} dts_status_t;
static struct pinctrl* this_pctrl; /* static pinctrl instance */
/* DTS state mapping name */
static const char* dts_state_name[STATE_MAX] = {
    "finger_cs_as_gpio",
    "finger_cs_as_spi_cs",
    "miso_as_gpio",
    "miso_as_spi_mi",
    "mosi_as_gpio",
    "mosi_as_spi_mo",
    "finger_clk_as_spi_clk_clr",
    "finger_clk_as_spi_clk",
    "finger_rst_low",
    "finger_rst_high",
    "finger_eint",
	"finger_power_high",
    "finger_power_low",
    "eint_clr",
    "eint_set",
};

/* pinctrl implementation */
inline static long dts_set_state(const char* name)
{
    long ret = 0;
    struct pinctrl_state* pin_state = 0;
    BUG_ON(!this_pctrl);
    pin_state = pinctrl_lookup_state(this_pctrl, name);

    if (IS_ERR(pin_state)) {
        pr_err("sunwave ----finger set state '%s' failed\n", name);
        ret = PTR_ERR(pin_state);
        return ret;
    }

    //printk("sunwave ---- dts_set_state = %s \n", name);
    /* select state! */
    ret = pinctrl_select_state(this_pctrl, pin_state);

    if ( ret < 0) {
        printk("sunwave --------pinctrl_select_state %s failed\n", name);
    }

    return ret;
}


inline static long dts_select_state(dts_status_t s)
{
    BUG_ON(!((unsigned int)(s) < (unsigned int)(STATE_MAX)));
    return dts_set_state(dts_state_name[s]);
}
int mt6755_dts_spi_mod(struct spi_device**  spi)
{
    dts_select_state(STATE_CS_SET);
    dts_select_state(STATE_MI_SET);
    dts_select_state(STATE_MO_SET);
    dts_select_state(STATE_CLK_SET);
    return 0;
}

int mt6755_dts_power(struct spi_device**  spi)
{
    dts_select_state(STATE_POWER_CLR);
    msleep(10);
    dts_select_state(STATE_POWER_SET);
    msleep(20);
    return 0;
}

int mt6755_dts_reset(struct spi_device**  spi)
{
    dts_select_state(STATE_RST_SET);
    //dts_select_state(STATE_EINT_SET);
    msleep(10);
    dts_select_state(STATE_RST_CLR);
    //dts_select_state(STATE_EINT_CLR);
    msleep(20);
    dts_select_state(STATE_RST_SET);
    //dts_select_state(STATE_EINT_SET);
    return 0;
}

static int  mt6755_dts_gpio_init(struct spi_device**   spidev)
{
    sunwave_sensor_t*  sunwave = spi_to_sunwave(spidev);
    struct device_node* finger_irq_node = NULL;
    struct spi_device*   spi = *spidev;
    /* set power pin to high */
#ifdef CONFIG_OF
    spi->dev.of_node = of_find_compatible_node(NULL, NULL, "mediatek,fingerprint");
    this_pctrl = devm_pinctrl_get(&spi->dev);

    if (IS_ERR(this_pctrl)) {
        //int ret = PTR_ERR(this_pctrl);
        dev_err(&spi->dev, "fwq Cannot find fp pctrl!\n");
        return -ENODEV;
    }

    //dts_select_state(STATE_DEFAULT);
    mt6755_dts_power(&spi);
    mt6755_dts_reset(&spi);
    mt6755_dts_spi_mod(&spi);
    dts_select_state(STATE_EINT);
    finger_irq_node = of_find_compatible_node(NULL, NULL, "mediatek,fingerprint");

    if (finger_irq_node) {
        u32 ints[2] = {0};
        of_property_read_u32_array(finger_irq_node, "debounce", ints, ARRAY_SIZE(ints));
        gpio_set_debounce(ints[0], ints[1]);
        sunwave->standby_irq = irq_of_parse_and_map(finger_irq_node, 0);
    }
    else {
        return -ENOMEM;
    }

#endif
    return 0;
}


static int  mt6755_dts_irq_hander(struct spi_device** spi)
{
    spi_to_sunwave(spi);
    return 0;
}


static int mt6755_dts_speed(struct spi_device**    spi, unsigned int speed)
{
#define SPI_MODULE_CLOCK   (100*1000*1000)
    struct mt_chip_conf* config;
    unsigned int    time = SPI_MODULE_CLOCK / speed;
    config = (struct mt_chip_conf*)(*spi)->controller_data;
    config->low_time = time / 2;
    config->high_time = time / 2;

    if (time % 2) {
        config->high_time = config->high_time + 1;
    }

    //(chip_config->low_time + chip_config->high_time);
    return 0;
}

static int mt6755_dts_com_mode(struct spi_device**    spi,unsigned int com_mode)
{
	struct mt_chip_conf* config;
	config = (struct mt_chip_conf*)(*spi)->controller_data;
	if((com_mode != DMA_TRANSFER)&&(com_mode != FIFO_TRANSFER))
	{
		sw_dbg("%s %d invaliad com_mode \n",__func__,__LINE__);
		return -1;
	}
	config->com_mod = com_mode;
	
	config->setuptime = 15;
    config->holdtime = 15;
    config->high_time = 21;
    config->low_time = 21;
    config->cs_idletime = 20;
    config->ulthgh_thrsh = 0;
    config->cpol = 0;
    config->cpha = 0;
    config->rx_mlsb = 1;
    config->tx_mlsb = 1;
    config->tx_endian = 0;
    config->rx_endian = 0;
    config->pause = 0;
    config->finish_intr = 1;
    config->deassert = 0;
    config->ulthigh = 0;
    config->tckdly = 0;
	
	sw_dbg("%s %d\n",__func__,__LINE__);
	return 0;
}

static finger_t  finger_sensor = {
    .ver                    = 0,
#if __SUNWAVE_SPI_DMA_MODE_EN
    .attribute              = DEVICE_ATTRIBUTE_NONE,
#else // SPI FIFO MODE
    .attribute              = DEVICE_ATTRIBUTE_SPI_FIFO,
#endif

    .write_then_read        = 0,
    .irq_hander             = mt6755_dts_irq_hander,
    .irq_request            = 0,
    .irq_free               = 0,
    .init                   = mt6755_dts_gpio_init,
    .power					= mt6755_dts_power,
    .reset                  = mt6755_dts_reset,
    .speed                  = mt6755_dts_speed,
    .com_mode				= mt6755_dts_com_mode,
};


void mt6755_dts_register_finger(sunwave_sensor_t*    sunwave)
{
    sunwave->finger = &finger_sensor;
}
EXPORT_SYMBOL_GPL(mt6755_dts_register_finger);
