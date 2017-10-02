//
//  variable.h
//  MyFirstOpenCV
//
//  Created by 张才明 on 2017/5/6.
//  Copyright © 2017年 CCNU. All rights reserved.
//

#ifndef variable_h
#define variable_h


#endif /* variable_h */
#include"process.h"

int pmsf_value = 5;//均值飘逸分割平滑系数
int MopEx_value = 2;//开运算
int Hmatch_value = 25;//模板匹配系数

//亮度
int V_low = 30;
int V_high = 250;
//饱和度
int S_low = 10;
int S_high = 170;
//色相
int H_low_max = 40;
int H_high_min = 100;
int if_high_light = 1; //是否高光补偿

IplImage *src = 0;
IplImage *srcResize = 0;
IplImage *img_YCrCb = 0;

CvSize sz;
CvSize newSize;
IplImage *tmp1;
IplImage *tmp2;
IplImage *tmp3;
IplImage *src1;
IplImage *src2;
IplImage *src3;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
IplImage *YCrCb;
IplImage *YCrCb_mask;
IplImage *Y_channel, *Cr_channel, *Cb_channel;
IplImage *Y_cmp, *Cr_cmp, *Cb_cmp;

CvScalar Y_lower;
CvScalar Y_upper;

CvScalar Cr_lower;
CvScalar Cr_upper;

CvScalar Cb_lower;
CvScalar Cb_upper;

CvScalar YCrCb_lower;
CvScalar YCrCb_upper;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////


IplImage* hsv_image;
IplImage* hsv_mask;
CvScalar  hsv_min;
CvScalar  hsv_max;

IplImage *H_img, *S_img, *V_img;
IplImage *H_mask, *H_mask1, *S_mask, *S_mask1, *V_mask, *V_mask1, *V_mask2;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//阀值化
IplImage* thd_src;
IplImage* thd_dst1;
IplImage* thd_dst2;
int thd_max = 255;
int thd_val = 100;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


IplImage* smooth1;
IplImage* smooth2;
IplImage* smooth3;
IplImage* smooth4;
IplImage* smooth5;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

//轮廓匹配

IplImage*    g_image = NULL;
IplImage*    g_gray = NULL;
int        g_thresh = 100;
CvMemStorage*  g_storage = NULL;
CvMemStorage*  g_storage1 = NULL;
CvMemStorage*  g_storage2 = NULL;

CvSeq* seqMidObj = 0;//塞选后的轮廓集合
int handNum = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

IplImage*    tmp_img = 0;
CvMemStorage*  storage_tmp = 0;

CvSeq* handT = 0;
CvSeq* handT1 = 0;
CvSeq* handT2 = 0;


int handTNum = 10;//10个模板


//const char *tmp_names[] = { "/Users/Camlin_Z/Downloads/Gesture_Template/1.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/2.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/3.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/4.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/5.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/6.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/7.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/8.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/9.bmp",
//    "/Users/Camlin_Z/Downloads/Gesture_Template/10.bmp" };

const char *tmp_names[] = { "/Users/Camlin_Z/Downloads/Gesture/1.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/2.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/3.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/4.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/5.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/6.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/7.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/8.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/9.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/10.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/11.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/12.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/13.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/14.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/15.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/16.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/17.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/18.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/19.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/20.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/21.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/22.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/23.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/24.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/25.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/26.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/27.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/28.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/29.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/30.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/31.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/32.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/33.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/34.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/35.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/36.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/37.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/38.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/39.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/40.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/41.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/42.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/43.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/44.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/45.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/46.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/47.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/48.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/49.bmp",
    "/Users/Camlin_Z/Downloads/Gesture/50.bmp",
};

char *num_c[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool if_match_num = false;
int match_num = -1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//拉普拉斯变换
int sigma = 2;
int smoothType = CV_GAUSSIAN;

IplImage* laplace = 0;
IplImage* colorlaplace = 0;
IplImage* planes[3] = { 0, 0, 0 };

int ls_low = 247;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define UP		-1
#define DOWN	1
#define LEFT	1
#define RIGHT	-1
CvPoint hand_center = cvPoint(0, 0); //按外接矩形求中心点
CvPoint hand_center_last = cvPoint(0, 0); //
CvPoint hand_direct_now = cvPoint(0, 0);  //本次监测到的移动方向
CvPoint hand_direct_last = cvPoint(0, 0); //上次监测到的移动方向
CvPoint hand_direct = cvPoint(0, 0);      //合成的方向
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

