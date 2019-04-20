/**************************************************
 ***************************************************
 for 6163a finger detect
 ***************************************************
 ***************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>

//#include "FpDetect.h"
//#ifndef PI
#define PI 3.14159265358979
//#endif
#define FFT_PRECISION 7
#define SIZE_POINT  32

//#if SIZE_POINT == 32
#define TWO_LEN 5
#define DIV_COMMEND  2

//#elif SIZE_POINT == 16
//#define TWO_LEN 4
//#define DIV_COMMEND  3
//#endif

#define	SL_PI			3.1415926
#define SL_2PI			6.2831852
#define SL_PI_DIV_2		1.570796
#define  ABS(x)  (((x) >= 0) ? (x) : -(x))
#define  GetMin(a,b,c)  ((a>b?b:a)>c ? c:(a>b?b:a))

typedef struct{
	int real;
	int img;
}complex_int;

//static int	SL_int_abs(int x);
//static void	SL_uchar_memcpy(unsigned char* dst, unsigned char* src, int iLength);
//static float 	Abs(float x) ;
//static long	SL_Sqrt(long x);
static int	SL_int_Sqrt(int x);
//static float	SL_Sin(float x);
//static float	SL_Cos(float x);
//static long	SL_Floor(long x);
static void 	add(complex_int a, complex_int b, complex_int *c);
static void 	sub(complex_int a, complex_int b, complex_int *c);
static void 	mul(complex_int a, complex_int b, complex_int *c);

//static void init_wn(complex_int *wn,int flag);
static void init_data(complex_int* in);
static void change_pos_xn(complex_int* input);
static void comput_butterflies(complex_int* in_out_put, complex_int* wn, int beg, int c_num, int k, int i);
static int DivRevise(int dividend);
static void fft(complex_int* in_out_put);
static void myFFT2D(int *fData, complex_int* scFFT, int BufLen);
static void FingerBLKTest(unsigned char* img, int width, int height, int* pResult);
//static complex_int wtest[16];

////////////////////////////////////////////////////////////////////////////////
/*
static int SL_int_abs(int x)
{
	if (x >= 0)
	{
		return x;
	}
	else
	{
		return -x;
	}
}


static float Abs(float x) 
{
	if(x<0)
		x=0-x;
		
	return x;
}
*/

/*
static void SL_uchar_memcpy(unsigned char* dst, unsigned char* src, int iLength)
{
	int i = 0;
	for (i = 0; i < iLength; i ++)
	{
		dst[i] = src[i];
	}
}


static long SL_Sqrt(long x)
{
	long xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f375a86 - (i >> 1);
	x = *(long*)&i;
	x = x*(1.5f - xhalf*x*x);
	x = x*(1.5f - xhalf*x*x);
	x = x*(1.5f - xhalf*x*x);
	return 1 / x;
}
*/

/*
static float SL_Sin(float x)
{

	 const float B = 1.2732395447; 
	 const float C = -0.4052847346;
	 const float P = 0.2310792853;//0.225; 
	 float y; 
	 
	 y = B * x + C * x * Abs(x);
	 y = P * (y * Abs(y) - y) + y;

	 return y;
}

static float SL_Cos(float x)
{
	const float Q = 1.5707963268;
	const float Pi =3.1415926536;
	x += Q; 

	if(x > Pi) 
		x -= 2 * Pi; 

	return	(SL_Sin(x));
}
*/
/*
static long SL_Floor(long x)
{
	if (x >= 0)
	{
		return (long)(int)(x);
	}
	else
	{
		if (((int)(x) - x) != 0.0f)
		{
			return (long)(int)(x) - 1;
		} 
		else
		{
			return (long)(int)(x);
		}
	}
}
*/
static int SL_int_Sqrt( int x )
{
	int n, n0, n1, temp, i;
	if (0 == x)
	{
		return 0;
	}
	temp = x;
	for (i = 0; temp > 0; i ++)
	{
		temp >>= 2;
	}
	n1 = 1 << i;
	n0 = n1 >> 1;

	while (n0 < n1)
	{
		n = ((n0 + n1) >> 1);

		if (x > ((int)n*n))
		{
			n0 = n + 1;
		}
		else
		{
			n1 = n - 1;
		}
	}
	if ((int)(n0 + 1) * (n0 + 1) <= x)
	{
		return n0 + 1;
	}
	else if ((int)n0 * n0 <= x)
	{
		return n0;
	} 
	else
	{
		return n0 - 1;
	}
}

static void add(complex_int a, complex_int b, complex_int *c)
{
	c->real = ((a.real + b.real) >> 1);
	c->img = ((a.img + b.img) >> 1);
}
static void sub(complex_int a, complex_int b, complex_int *c)
{
	c->real = ((a.real - b.real) >> 1);
	c->img = ((a.img - b.img) >> 1);
}
static void mul(complex_int a, complex_int b, complex_int *c)
{
	c->real = ((a.real*b.real) >> 7) - ((a.img*b.img) >> 7);
	c->img = ((a.real*b.img) >> 7) + ((a.img*b.real) >> 7);
}

///////////////////////////////////////////////////////////////////////////
static void init_data(complex_int* in)
{
	int i = 0 ;
	for (i = 0; i < SIZE_POINT; i++)
	{
		in[i].real <<= FFT_PRECISION;
		in[i].img  <<= FFT_PRECISION;
	}

}
/*
static void init_wn(complex_int *wn,int flag)
{
	int i = 0;
	//complex_int wtest[16];
	if (flag == 1)
	{
		for (i = 0; i < SIZE_POINT / 2; i++)
		{
			wn[i].real = (int)(SL_Cos(2 * PI / SIZE_POINT * i) * 128);
			wn[i].img = (int)(-1 * SL_Sin(2 * PI / SIZE_POINT * i) * 128);

//			wtest[i].real = (int)(SL_Cos(2 * PI / SIZE_POINT * i) * 128);
//			wtest[i].img = (int)(-1 * SL_Sin(2 * PI / SIZE_POINT * i) * 128);
		}
	}
	else
	{
		for (i = 0; i < SIZE_POINT / 2; i++)
		{
			wn[i].real = (int)(SL_Cos(2 * PI / SIZE_POINT * i) * 128);
			wn[i].img = (int)(SL_Sin(2 * PI / SIZE_POINT * i) * 128);

			//wtest[i].real = (int)(SL_Cos(2 * PI / SIZE_POINT * i) * 128);
			//wtest[i].img = (int)(SL_Sin(2 * PI / SIZE_POINT * i) * 128);
		}
	}
	//memcpy();
	//memcpy(wn, wtest, sizeof(wtest));
}
*/
static void change_pos_xn(complex_int* input)
{
	complex_int temp;
	int i = 0, j = 0, k = 0;
	int t;
	for (i = 0; i<SIZE_POINT; i++)
	{
		k = i; j = 0;
		t = TWO_LEN;
		while (t--)
		{
			j = j << 1;
			j |= (k & 1);
			k = k >> 1;
		}
		if (j>i)
		{
			temp = input[i];
			input[i] = input[j];
			input[j] = temp;
		}
	}
}

static void comput_butterflies(complex_int* in_out_put, complex_int* wn, int beg, int c_num, int k, int i)
{
//	int temp_real = 0, temp_img = 0;
	complex_int up, down;
	int a, b, p = 1;
	a = beg + k;
	b = beg + k + c_num / 2;
	p <<= (TWO_LEN - 1 - i);
	p = k*p;
	mul(in_out_put[b], wn[p], &up);
	add(in_out_put[a], up, &up);
	mul(in_out_put[b], wn[p], &down);
	sub(in_out_put[a], down, &down);
	in_out_put[a] = up;
	in_out_put[b] = down;
	p = 1;
}

static int DivRevise(int dividend)
{
	
	int temp = (dividend * 10) >> DIV_COMMEND; 
	int Res = 0;
	if (temp >= 0)
	{
		Res = (int)((temp + 5) / 10);
	}
	else 
	{
		Res = (int)((temp - 5) / 10);
	}
	return Res;
}

static void fft(complex_int* in_out_put)
{
	
	//complex_int *wn = (complex_int *)vmalloc(/*sizeof((complex_int)*SIZE_POINT/2+2)*/ (8 * (SIZE_POINT/2+2)));

	int  i = 0, j = 0, k = 0;
	int  L = 1, c_num = 1, beg;   
 	int realv[] = {128,125,118,106,90,71,48,24,0,-24,-48,-71,-90,-106,-118,-125};
	int imgv[] = {0,-24,-48,-71,-90,-106,-118,-125,-128,-125,-118,-106,-90,-71,-48,-24};	
	//complex_int up, down;
	//int a, b, p = 1;

	complex_int wnnn[18];
	init_data(in_out_put);
	
	//init_wn(wn,1);
#if 0
	for (i = 0; i < SIZE_POINT / 2; i++)
	{
		wnnn[i].real = (int)(SL_Cos(2 * PI / SIZE_POINT * i) * 128);
		wnnn[i].img = (int)(-1 * SL_Sin(2 * PI / SIZE_POINT * i) * 128);
	}
#endif
#if 1

	for (i = 0; i < SIZE_POINT / 2; i++)
	{
		wnnn[i].real = realv[i];
		wnnn[i].img = imgv[i];
	} 
#endif

	change_pos_xn(in_out_put);
	
	for (i = 0; i < TWO_LEN; i++)
	{
		L <<= (TWO_LEN - i - 1);
		for (j = 0; j < L; j++)
		{
			c_num <<= (i + 1);
			beg = j*c_num;
			for (k = 0; k < c_num / 2; k++)
			{
				comput_butterflies(in_out_put, wnnn, beg, c_num, k, i);				
			}
			c_num = 1;
		}
		L = 1;
	}

	for (i = 0; i < SIZE_POINT; i++)
	{
		in_out_put[i].real = DivRevise(in_out_put[i].real);
		in_out_put[i].img  = DivRevise(in_out_put[i].img);
	}
	//vfree(wn);
}

static void myFFT2D(int *fData, complex_int* scFFT, int BufLen)
{
	complex_int* scLine = (complex_int*)kmalloc(sizeof(complex_int) * 2*BufLen, GFP_KERNEL);
	//complex_int* scLine = (complex_int*)malloc(sizeof(complex_int) * 2*BufLen);
	int iIndex,iIndex1;
	//complex_int * scTemp96 = scLine + BufLen;
	complex_int scMean;
	for (iIndex = 0; iIndex < BufLen; iIndex ++)
	{
		memset(scLine, 0, sizeof(complex_int) * BufLen);
		//SL_compx_array_set_zero(scLine, BufLen);
		for ( iIndex1 = 0; iIndex1 < BufLen; iIndex1 ++)
		{
			scLine[iIndex1].real = fData[iIndex * BufLen + iIndex1];
		}
		scMean.img = 0;
		scMean.real = 0;
		for ( iIndex1 = 0; iIndex1 < BufLen; iIndex1 ++)
		{
			scMean.real += scLine[iIndex1].real;
			scMean.img += scLine[iIndex1].img;
		}
		scMean.real /= BufLen;
		scMean.img /= BufLen;
		for ( iIndex1 = 0; iIndex1 < BufLen; iIndex1 ++)
		{
			scLine[iIndex1].real -= scMean.real;
			scLine[iIndex1].img -= scMean.img;
		}

		fft(scLine);
		memcpy(scFFT + iIndex * BufLen, scLine, sizeof(complex_int) * BufLen);
		//SL_compx_memcpy(scFFT + iIndex * BufLen, scLine, BufLen);
	}
	for (iIndex = 0; iIndex < BufLen; iIndex ++)
	{
		for (iIndex1 = 0; iIndex1 < BufLen; iIndex1 ++)
		{
			scLine[iIndex1] = scFFT[iIndex1 * BufLen + iIndex];
		}
		scMean.img = 0;
		scMean.real = 0;
		for ( iIndex1 = 0; iIndex1 < BufLen; iIndex1 ++)
		{
			scMean.real += scLine[iIndex1].real;
			scMean.img += scLine[iIndex1].img;
		}
		scMean.real /= BufLen;
		scMean.img /= BufLen;
		for ( iIndex1 = 0; iIndex1 < BufLen; iIndex1 ++)
		{
			scLine[iIndex1].real -= scMean.real;
			scLine[iIndex1].img -= scMean.img;
		}
		fft(scLine);
		for (iIndex1 = 0; iIndex1 < BufLen; iIndex1 ++)
		{
			scFFT[iIndex1 * BufLen + iIndex] = scLine[iIndex1];
		}
	}
	kfree(scLine);
	//free(scLine);
}

static void FFTShift(complex_int* scFFT,int BufLen)
{
	int HalfLen = BufLen / 2;
	int i = 0;
	complex_int* scTemp = (complex_int*)kmalloc(sizeof(complex_int) * HalfLen, GFP_KERNEL);
	//complex_int* scTemp = (complex_int*)malloc(sizeof(complex_int) * HalfLen);
	for (i = 0; i < HalfLen; i ++)
	{
		memcpy(scTemp, scFFT + i * BufLen, sizeof(complex_int) * HalfLen);
		memcpy(scFFT + i*BufLen, scFFT + (i + HalfLen) * BufLen + HalfLen, sizeof(complex_int) * HalfLen);
		memcpy(scFFT + (i + HalfLen) * BufLen + HalfLen, scTemp, sizeof(complex_int) * HalfLen);
		memcpy(scTemp, scFFT + (i + HalfLen) * BufLen, sizeof(complex_int) * HalfLen);
		memcpy(scFFT + (i + HalfLen) * BufLen, scFFT + i * BufLen + HalfLen, sizeof(complex_int) * HalfLen);
		memcpy(scFFT + i * BufLen + HalfLen, scTemp, sizeof(complex_int) * HalfLen);
	}
	kfree(scTemp);
	//free(scTemp);
}

static void DeleteLowFrequency(complex_int* scFFT, int* pfBuf, int BufLen, int iResultLen)
{
	int i,j = 0;
	int iCutLen = (BufLen - iResultLen - 2) / 2;
	int iHalfLen = iResultLen / 2;
	for (i = 0; i < iHalfLen; i ++)
	{
		for (j = 0; j < iHalfLen; j ++)
		{
			pfBuf[j * iResultLen + i] = 
				SL_int_Sqrt(scFFT[(j + iCutLen) * BufLen + i + iCutLen].real * 
				scFFT[(j + iCutLen) * BufLen + i + iCutLen].real + 
				scFFT[(j + iCutLen) * BufLen + i + iCutLen].img * 
				scFFT[(j + iCutLen) * BufLen + i + iCutLen].img);
			pfBuf[j * iResultLen + i + iHalfLen] = 
				SL_int_Sqrt(scFFT[(j + iCutLen) * BufLen + i + iHalfLen + 2 + iCutLen].real * 
				scFFT[(j + iCutLen) * BufLen + i + iHalfLen + 2 + iCutLen].real + 
				scFFT[(j + iCutLen) * BufLen + i + iHalfLen + 2 + iCutLen].img * 
				scFFT[(j + iCutLen) * BufLen + i + iHalfLen + 2 + iCutLen].img);
			pfBuf[(j + iHalfLen) * iResultLen + i] = 
				SL_int_Sqrt(scFFT[(j + iHalfLen + 2 + iCutLen) * BufLen + i + iCutLen].real * 
				scFFT[(j + iHalfLen + 2 + iCutLen) * BufLen + i + iCutLen].real + 
				scFFT[(j + iHalfLen + 2 + iCutLen) * BufLen + i + iCutLen].img * 
				scFFT[(j + iHalfLen + 2 + iCutLen) * BufLen + i + iCutLen].img);
			pfBuf[(j + iHalfLen) * iResultLen + i + iHalfLen] = 
				SL_int_Sqrt(scFFT[(j + iHalfLen + 2  + iCutLen) * BufLen + i + iHalfLen + 2  + iCutLen].real * 
				scFFT[(j + iHalfLen + 2  + iCutLen) * BufLen + i + iHalfLen + 2  + iCutLen].real + 
				scFFT[(j + iHalfLen + 2  + iCutLen) * BufLen + i + iHalfLen + 2  + iCutLen].img * 
				scFFT[(j + iHalfLen + 2  + iCutLen) * BufLen + i + iHalfLen + 2  + iCutLen].img);
		}
		}
}


static void FingerBLKTest(unsigned char* img, int width, int height, int* pResult)
{
     int i,j/*, iIndex = 0*/;
	int BufLen = 32;
	int BufSize = BufLen*BufLen;
	//int ExpSize = 8;
	int iFFTReverseLen = 24;

	int fMean = 0;
	int fMax = 0;
	
	int iBlkWidthStart = (width - BufLen)/2;
	int iBlkHeightStart = (height - BufLen)/2;

	int* pfBuf = (int*)kmalloc(sizeof(int)*BufSize, GFP_KERNEL);
	complex_int* scFFT = (complex_int*)kmalloc(sizeof(complex_int)*BufSize, GFP_KERNEL);
	
	//int* pfBuf = (int*)malloc(sizeof(int)*BufSize);
	//complex_int* scFFT = (complex_int*)malloc(sizeof(complex_int)*BufSize);

	for(i = 0 ; i < BufLen; i ++)
	{
		for(j = 0; j < BufLen; j ++)
		{
			pfBuf[j * BufLen + i] = 
				(int)(img[(j + iBlkHeightStart) * width + (i + iBlkWidthStart)]);
		}
	}
	memset(scFFT, 0, sizeof(complex_int) * BufSize);
	myFFT2D(pfBuf, scFFT, BufLen);
	FFTShift(scFFT,BufLen);
	DeleteLowFrequency(scFFT, pfBuf, BufLen, iFFTReverseLen);
	fMean = 0;
	fMax = pfBuf[0];
	for (i = 7; i < 17; i++)
	{
		for (j = 7; j < 17; j ++)
		{
			if (fMax < pfBuf[j + i * iFFTReverseLen])
			{
				fMax = pfBuf[j + i * iFFTReverseLen];
			}
		}		
	}
	for (i = 0; i < 5; i ++)
	{
		for (j = 0; j < 5; j ++)
		{
			fMean += pfBuf[j + i * iFFTReverseLen];
		}
	}
	fMean /= 25;
	if (fMean == 0)
	{
		*pResult = -1;
	}
	else
	{
		*pResult = fMax/fMean;
	}
	kfree(scFFT);
	kfree(pfBuf);
	
	//free(scFFT);
	//free(pfBuf);
}


int FingerDetectBLK_test(unsigned char* img,int iImgHeight,int iImgWidth,int ifftMin)
{
	int iFFTMeasureBLK = 0;


	FingerBLKTest(img, iImgWidth, iImgHeight,&iFFTMeasureBLK);

	if (iFFTMeasureBLK >= ifftMin)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
EXPORT_SYMBOL_GPL(FingerDetectBLK_test);
