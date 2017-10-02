////
////  二值化图像.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/5/9.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <opencv2/opencv.hpp>
//using namespace std;
//
//IplImage *g_pGrayImage = NULL;
//IplImage *g_pBinaryImage = NULL;
//const char *pstrWindowsBinaryTitle = "二值图";
//const char *pstrWindowsSrcTitle = "原图";
//const char *pstrWindowsToolBarName = "二值图阈值";
//
//void on_trackbar(int pos)
//{
//    // cvThreshold(const CvArr *src, CvArr *dst, double threshold, double max_value, int threshold_type)
//    // 第一个参数表示输入图像，必须为单通道灰度图,第二个参数表示输出的边缘图像，为单通道黑白图,第三个参数表示阈值,第四个参数表示最大值
//    // 第五个参数表示运算方法 CV_THRESH_BINARY (value = value > threshold ? max_value : 0)
//    cvThreshold(g_pGrayImage, g_pBinaryImage, pos, 255, CV_THRESH_BINARY);
//    // 显示二值图
//    cvShowImage(pstrWindowsBinaryTitle, g_pBinaryImage);
//}
//
//int main( int argc, char** argv )
//{
//    // 从文件中加载原图
//    IplImage *pSrcImage = cvLoadImage("/Users/Camlin_Z/Downloads/3.JPG", CV_LOAD_IMAGE_UNCHANGED);
//    
//    // 转为灰度图
//    g_pGrayImage =  cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
//    cvCvtColor(pSrcImage, g_pGrayImage, CV_BGR2GRAY);
//    
//    // 创建二值图
//    g_pBinaryImage = cvCreateImage(cvGetSize(g_pGrayImage), IPL_DEPTH_8U, 1);
//    
//    // 显示原图
//    cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
//    cvShowImage(pstrWindowsSrcTitle, pSrcImage);
//    // 创建二值图窗口
//    cvNamedWindow(pstrWindowsBinaryTitle, CV_WINDOW_AUTOSIZE);
//    
//    // 滑动条
//    int nThreshold = 0;
//    cvCreateTrackbar(pstrWindowsToolBarName, pstrWindowsBinaryTitle, &nThreshold, 254, on_trackbar);
//    
//    on_trackbar(1);
//    
//    cvWaitKey(0);
//    
//    cvDestroyWindow(pstrWindowsSrcTitle);
//    cvDestroyWindow(pstrWindowsBinaryTitle);
//    cvReleaseImage(&pSrcImage);
//    cvReleaseImage(&g_pGrayImage);
//    cvReleaseImage(&g_pBinaryImage);
//    return 0;
//}
