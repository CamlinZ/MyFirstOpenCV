////
////  检测并标识人脸.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/4/13.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include "opencv2/core/core_c.h"
//#include "opencv2/ml/ml.hpp"
//
//const char* cascade_name = "/Users/Camlin_Z/资料/OpenCV/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml";
//CvHaarClassifierCascade* cascade = (CvHaarClassifierCascade*)cvLoad(cascade_name, 0, 0, 0);
//
//void detect_and_draw(IplImage* img, double scale){
//    //定义一个颜色向量的静态数组，可以用不同的颜色标识出人脸
//    static CvScalar colors[] = {
//        {0,0,255}, {0,128,255}, {0,255,255}, {0,255,0}, {255,128,0}, {255,255,0}, {255,0,0}, {255,0,255}
//    };
//    IplImage* gray = cvCreateImage(cvSize(img->width, img->height), 8, 1);
//    
//    //cvRound()：用于对一个double型数据进行四舍五入。
//    IplImage* small_img = cvCreateImage(cvSize(cvRound(img->width/scale), cvRound(img->height/scale)), 8, 1);
//    
//    //颜色空间转换函数，实现RGB颜色向HSV，HSI，GRAY等颜色阈的转换
//    cvCvtColor(img, gray, CV_BGR2GRAY);
//    
//    //实现图像的缩放，第一个参数是输入图像，第二个参数是输出图像，第三个参数是差值方法：CV_INTER_NN 最近邻差值, CV_INTER_LINEAR 双线性差值 (缺省使用)
//    //CV_INTER_AREA 使用象素关系重采样。当图像缩小时候，该方法可以避免波纹出现。当图像放大时，类似于CV_INTER_NN方法,CV_INTER_CUBIC 立方差值。
//    cvResize(gray, small_img, CV_INTER_LINEAR);
//    
//    //实现灰度图像的直方图均衡化,这样可以平衡亮度值，因为积分涂先锋特征基于不同的矩阵区域的差别，如果直方图没哟均衡化，这些差别可能由于测试图像的成像条件或过分曝光而偏离正常值
//    cvEqualizeHist(small_img, small_img);
//    
//    //设置缓存区
//    CvMemStorage *storage = cvCreateMemStorage(0);
//    cvClearMemStorage(storage);
//    
//    /* Haar分类器函数解释：
//        cvHaarDetectObjects(
//              const CvArr* image,               //表示输入图像，尽量使用灰度图以加快检测速度。
//              CvHaarClassifierCascade* cascade,     //表示Haar特征分类器，可以用cvLoad()函数来从磁盘中加载xml文件作为Haar特征分类器。
//              CvMemStorage* storage,            //用来存储检测到的候选目标的内存缓存区域。
//              double scale_factor CV_DEFAULT(1.1),      //表示在前后两次相继的扫描中，搜索窗口的比例系数。默认为1.1即每次搜索窗口依次扩大10%
//              int min_neighbors CV_DEFAULT(3),      //表示构成检测目标的相邻矩形的最小个数(默认为3个)。如果组成检测目标的小矩形的个数和小于
//                                                     min_neighbors-1都会被排除。如果min_neighbors为0, 则函数不做任何操作就返回所有的被检候选矩形框，
//                                                     这种设定值一般用在用户自定义对检测结果的组合程序上。
//              int flags CV_DEFAULT(0),          //要么使用默认值，要么使用CV_HAAR_DO_CANNY_PRUNING，如果设置为CV_HAAR_DO_CANNY_PRUNING，
//                                                    那么函数将会使用Canny边缘检测来排除边缘过多或过少的区域，因此这些区域通常不会是人脸所在区域。
//              CvSize min_size CV_DEFAULT(cvSize(0,0)),      //表示检测窗口的最小值，一般设置为默认即可
//              CvSize max_size CV_DEFAULT(cvSize(0,0))       //表示检测窗口的最大值，一般设置为默认即可。
//          );
//     */
//    CvSeq* objects = cvHaarDetectObjects(small_img, cascade, storage, 1.1, 3, 0, cvSize(0, 0), cvSize(30, 30));
//    printf("人脸个数: %d\n", objects->total);
//    
//    //for循环用于逐个取出人脸的矩形区域，然后用不同的颜色通过函数cvRectangle()画出来
//    for (int i = 0; i < (objects ? objects->total : 0); i++ ) {
//        CvRect* r = (CvRect*)cvGetSeqElem(objects, i);
//        cvRectangle(img, cvPoint(r->x, r->y), cvPoint(r->x+r->width, r->y+r->height), colors[i % 8]);
//    }
//    
//    cvNamedWindow("result", CV_WINDOW_AUTOSIZE);
//    cvShowImage("result", img);
//    
//    cvReleaseImage(&gray);
//    cvReleaseImage(&small_img);
//    
//}
//
//int main(){
//    double scale = 1.3;
//    if(cascade) {
//        printf("分类器加载失败！\n");
//        return -1;
//    }
//    else
//        printf("分类器加载成功！");
//    const char* FileName = "/Users/Camlin_Z/Downloads/2.JPG";
//    IplImage* testImg = cvLoadImage(FileName, CV_LOAD_IMAGE_UNCHANGED);
//    detect_and_draw(testImg, scale);
//    cvWaitKey(0);
//    return 0;
//}
//
////using namespace std;
////int main()
////{
////    
////    // 【1】加载分类器
////    // 加载Haar特征检测分类器
////    // 将haarcascade_frontalface_alt2.xml拷至项目目录下，便于操作
////    const char *pstrCascadeFileName = "/Users/Camlin_Z/资料/OpenCV/sources/data/haarcascades/haarcascade_frontalface_alt2.xml";
////    CvHaarClassifierCascade *pHaarCascade = NULL;
////    
////    pHaarCascade = (CvHaarClassifierCascade*)cvLoad(pstrCascadeFileName);
////    if(!pHaarCascade) {printf("分类器加载失败\n");return -1;}
////    else printf("加载成功！！！");
////    
////    
////    // 【2】载入图像
////    const char *pstrImageName = "/Users/Camlin_Z/Downloads/2.JPG";
////    IplImage *pSrcImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
////    
////    IplImage *pGrayImage = cvCreateImage(cvGetSize(pSrcImage), IPL_DEPTH_8U, 1);
////    cvCvtColor(pSrcImage, pGrayImage, CV_BGR2GRAY); // 转化成灰度图，提高检测速度
////    
////    // 标记颜色
////    CvScalar FaceCirclecolors[] =
////    {
////        {{0, 0, 255}},
////        {{0, 128, 255}},
////        {{0, 255, 255}},
////        {{0, 255, 0}},
////        {{255, 128, 0}},
////        {{255, 255, 0}},
////        {{255, 0, 0}},
////        {{255, 0, 255}}
////    };
////    
////    // 设置缓存区
////    CvMemStorage *pcvMStorage = cvCreateMemStorage(0);
////    cvClearMemStorage(pcvMStorage);
////    // 【3】识别
////    CvSeq *pcvSeqFaces = cvHaarDetectObjects(pGrayImage, pHaarCascade, pcvMStorage);
////    printf("人脸个数: %d\n", pcvSeqFaces->total);
////    
////    // 【4】标记
////    for(int i = 0; i <pcvSeqFaces->total; i++)
////    {
////        CvRect* r = (CvRect*)cvGetSeqElem(pcvSeqFaces, i);
////        CvPoint center;
////        int radius;
////        center.x = cvRound((r->x + r->width * 0.5));
////        center.y = cvRound((r->y + r->height * 0.5));
////        radius = cvRound((r->width + r->height) * 0.25);
////        cvCircle(pSrcImage, center, radius, FaceCirclecolors[i % 8], 2);
////    }
////    cvReleaseMemStorage(&pcvMStorage); // 释放缓存
////    
////    // 【5】显示
////    const char *pstrWindowsTitle = "【人脸识别】";
////    cvShowImage(pstrWindowsTitle, pSrcImage);
////    
////    cvWaitKey(0);
////    return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
