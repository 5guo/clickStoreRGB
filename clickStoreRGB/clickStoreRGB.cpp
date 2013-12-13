// clickStoreRGB.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace::std;
using namespace::cv;

void dispplex(IplImage*img,char*var1,char*var2 , char* var3,int x,int y)
{
	CvFont font;
	cvInitFont(&font,CV_FONT_HERSHEY_SCRIPT_COMPLEX,1.0,1.0);
	cvPutText(img,var1,cvPoint(x,y),&font,cvScalar(255,255,0));
	cvPutText(img,var2,cvPoint(x+100,y),&font,cvScalar(255,255,0));
	cvPutText(img,var3,cvPoint(x+200,y),&font,cvScalar(255,255,0));
	cvShowImage("demo",img);

}

void cvmovecallback(int event,int x,int y,int flags,void*para)
{
	IplImage*img=(IplImage*)para;
	switch(event){
	case CV_EVENT_LBUTTONDOWN:
		{
			uchar *rgb;
			rgb=(uchar*)(img->imageData+y*(img->widthStep)+(img->nChannels)*x);
			char var1[5];
				itoa((int)rgb[1],var1,10);
			char var2[5];
				itoa((int)rgb[2],var2,10);
				char var3[5];
				itoa((int)rgb[3],var3,10);
			dispplex(img,var1,var2,var3,x,y);
		break;	
		}
	default:break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	IplImage *img=cvLoadImage("adc.bmp");
	int x=0;
	int y=0;
	cvNamedWindow("demo");
	// cvSetMouseCallback("demo",cvmovecallback,(void*)img);
	cvShowImage("demo",img);

	cvWaitKey(0);

	return 0;
}

