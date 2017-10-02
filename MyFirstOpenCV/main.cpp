////
////  main.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/3/25.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include"process.h"
////#include"variable.h"
//
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
//extern CvSize sz;
//extern CvSize newSize;
//extern IplImage *tmp1;
//extern IplImage *tmp2;
//extern IplImage *tmp3;
//extern IplImage *src1;
//extern IplImage *src2;
//extern IplImage *src3;
//extern IplImage* smooth1;
//extern IplImage* smooth2;
//extern IplImage* smooth3;
//extern IplImage* smooth4;
//extern IplImage* smooth5;
//extern CvSeq* handT ;
//extern int match_num;
//extern int pmsf_value ;//均值飘逸分割平滑系数
//extern CvSeq* seqMidObj;//塞选后的轮廓集合
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int main()
//{
//    int c = 0;
//    double scale = 0.5;
//    //打开摄像头
//    //CvCapture* capture = cvCaptureFromCAM(1);
//    cv::VideoCapture Capture(0);
//    if (!Capture.isOpened())
//    {
//        return -1;
//    }
//    //扑捉第一帧图像
//    cv::Mat frame_sr;
//    Capture >> frame_sr;
//    //mat结构向IplImage转换
//    IplImage imgTmp = frame_sr;
//    IplImage *src = cvCloneImage(&imgTmp);
//    //获得图像大小
//    sz = cvGetSize(src);
//    newSize.height = (int)(sz.height * scale);
//    newSize.width = (int)(sz.width * scale);
//    sz = newSize;
//    //重新调整图像大小
//    //resizeSrc();
//    
//    //建立所有窗体
//    resizeAllWindow();
//    
//    tmp1 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    
//    tmp2 = cvCreateImage(sz, IPL_DEPTH_8U, 3);
//    
//    tmp3 = cvCreateImage(sz, IPL_DEPTH_8U, 3);
//    
//    src1 = cvCreateImage(sz, IPL_DEPTH_8U, 3);
//    src2 = cvCreateImage(sz, IPL_DEPTH_8U, 3);
//    src3 = cvCreateImage(sz, IPL_DEPTH_8U, 3);
//    
//    smooth1 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    smooth2 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    smooth3 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    smooth4 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    smooth5 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    
//    init_hand_YCrCb();
//    init_hand_HSV();
//    init_laplace();
//    inti_threshold();
//    //载入匹配的模板
//    init_hand_template();
//    
//    /////////////////////开始循环///////////////////////////////
//    while (c != 27)
//    {
//        //继续扑捉当前视频贞
//        Capture >> frame_sr;
//        sharpenImage1(frame_sr, frame_sr);//图像进行锐化处理
//        
//        IplImage imgTmp = frame_sr;
//        IplImage *src = cvCloneImage(&imgTmp);
//        
//        //缩小要处理的图像(减小运算量)
//        cvResize(src, src1, CV_INTER_LINEAR);
//        
//        cvShowImage("src", src1);
//        cvPyrMeanShiftFiltering(src1, src2, pmsf_value, 40, 2);
//        cvSmooth(src2, src3, CV_GAUSSIAN,3, 0, 0, 0);
//        cvShowImage("高斯去噪", src3);
//        
//        //sharpenImage1(src2, src2);//图像进行锐化处理
//        //cvCvtColor(src2, src2, CV_BGR2YCrCb);
//        //cvConvertScale(src2, src2, 1.0 / 255.0, 0);//将原图RGB归一化到0-1之间
//        //cvCvtColor(src2, src2, CV_BGR2HSV);//得到HSV图
//        //cvShowImage( "均值漂移分割", tmp4);
//        
//        //拉普拉斯变换主要用于边缘检测
//        toLaplace(src3);
//        
//        ////hsv色彩提取
//        hand_HSV();
//        ////YCrCb色彩提取
//        //hand_YCrCb();
//        
//        
//        
//        ////阀值化
//        //threshold();
//        
//        ////降噪
//        reduce_noise();
//        
//        ////寻找手轮廓
//        hand_contours(smooth1);
//        ////hand_contours(planes[2]);
//        ////hand_contours(tmp2);
//        
//        ////处理(未使用)
//        ////handProcess(seqMidObj);
//        
//        ////寻找匹配
//        hand_template_match(handT, seqMidObj);
//        
//        ////求手的移动方向
//        hand_direction(seqMidObj);
//        
//        ////绘制额外信息
//        cvZero(tmp2);
//        hand_draw(tmp2, seqMidObj); //绘制在检测窗口
//        hand_draw(src1, seqMidObj); //绘制在原窗口
//        
//        ////cvShowImage( "扩张腐蚀", smooth1);
//        cvShowImage("最终识别", tmp2);
//        cvShowImage("src", src1);
//        
//        //控制鼠标(当拳头状, 则控制鼠标移动)
//        //if(match_num == 10) control_mouse(hand_direct.x, hand_direct.y);
//        printf("\n");
//        c = cvWaitKey(10);
//    }
//    ////////////////////////////////////////////////////////////
//    //cvReleaseCapture(&scr);
//    cvDestroyAllWindows();
//    
//    return 0;
//    
//    
//}
