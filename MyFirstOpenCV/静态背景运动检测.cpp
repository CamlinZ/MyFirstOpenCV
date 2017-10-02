////
////  静态背景运动检测.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/4/30.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//int main(int argc, char** argv){
//    //声明IplImage指针
//    IplImage* pFrame = NULL;
//    IplImage* pFrImg = NULL;
//    IplImage* pBkImg = NULL;
//    CvMat* pFrameMat = NULL;
//    CvMat* pFrMat = NULL;
//    CvMat* pBkMat = NULL;
//    CvCapture* pCapture = NULL;
//    int nFrmNum = 0;
//    //创建窗口
//    cvNamedWindow("video", 1);
//    cvNamedWindow("background",1);
//    cvNamedWindow("foreground",1);
//    //使窗口有序排列
//    cvMoveWindow("video", 30, 0);
//    cvMoveWindow("background", 360, 0);
//    cvMoveWindow("foreground", 690, 0);
//    //pCapture = cvCaptureFromAVI("2.avi");   //读入已有视频用此句
//    pCapture = cvCreateCameraCapture(CV_CAP_ANY);           //从摄像头读入视频用此
//    while(pFrame = cvQueryFrame( pCapture ))
//    {
//        nFrmNum++;
//        //如果是第一帧，需要申请内存，并初始化
//        if(nFrmNum == 1)
//        {
//            pBkImg = cvCreateImage(cvSize(pFrame->width, pFrame->height),IPL_DEPTH_8U,1);
//            pFrImg = cvCreateImage(cvSize(pFrame->width, pFrame->height), IPL_DEPTH_8U,1);
//            pBkMat = cvCreateMat(pFrame->height, pFrame->width, CV_32FC1);
//            pFrMat = cvCreateMat(pFrame->height, pFrame->width, CV_32FC1);
//            pFrameMat = cvCreateMat(pFrame->height, pFrame->width, CV_32FC1);
//            //转化成单通道图像再处理
//            cvCvtColor(pFrame, pBkImg, CV_BGR2GRAY);
//            cvCvtColor(pFrame, pFrImg, CV_BGR2GRAY);
//            cvConvert(pFrImg, pFrameMat);
//            cvConvert(pFrImg, pFrMat);
//            cvConvert(pFrImg, pBkMat);
//        }
//        else
//        {
//            cvCvtColor(pFrame, pFrImg, CV_BGR2GRAY);
//            cvConvert(pFrImg, pFrameMat);
//            //先做高斯滤波，以平滑图像
//            cvSmooth(pFrameMat, pFrameMat, CV_GAUSSIAN, 3, 0, 0);
//            //当前帧跟背景图相减
//            cvAbsDiff(pFrameMat, pBkMat, pFrMat);
//            //二值化前景图
//            cvThreshold(pFrMat, pFrImg, 10, 255.0, CV_THRESH_BINARY);
//            //更新背景
//            cvRunningAvg(pFrameMat, pBkMat, 0.003, 0);
//            //将背景转化为图像格式，用以显示
//            cvConvert(pBkMat, pBkImg);
//            pFrame->origin = IPL_ORIGIN_BL;
//            pFrImg->origin = IPL_ORIGIN_BL;
//            pBkImg->origin = IPL_ORIGIN_BL;
//            cvShowImage("video", pFrame);
//            cvShowImage("background", pBkImg);
//            cvShowImage("foreground", pFrImg);
//            //如果有按键事件，则跳出循环
//            //此等待也为cvShowImage函数提供时间完成显示
//            //等待时间可以根据CPU速度调整
//            char c = cvWaitKey(2000);
//            if (c == 27) {
//                break;
//            }
//        }
//    }
//    //销毁窗口
//    cvDestroyWindow("video");
//    cvDestroyWindow("background");  
//    cvDestroyWindow("foreground");  
//    //释放图像和矩阵  
//    cvReleaseImage(&pFrImg);  
//    cvReleaseImage(&pBkImg);  
//    cvReleaseMat(&pFrameMat);  
//    cvReleaseMat(&pFrMat);  
//    cvReleaseMat(&pBkMat);  
//    cvReleaseCapture(&pCapture);
//
//}
