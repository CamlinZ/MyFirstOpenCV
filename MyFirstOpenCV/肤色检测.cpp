////
////  肤色检测.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/5/6.
////  Copyright © 2017年 CCNU. All rights reserved.
////
////
////**********************************************************************
///*
// Description:    手势检测
// 先滤波去噪
// -->转换到HSV空间
// -->根据皮肤在HSV空间的分布做出阈值判断，这里用到了inRange函数，
// 然后进行一下形态学的操作，去除噪声干扰，是手的边界更加清晰平滑
// -->得到的2值图像后用findContours找出手的轮廓，去除伪轮廓后，再用convexHull函数得到凸包络
// Author:         Yang Xian
// Email:          yang_xian521@163.com
// Version:        2011-11-2
// History:
// */
//
//#include <iostream>   // for standard I/O
//#include <string>   // for strings
//#include <iomanip>  // for controlling float print precision
//#include <sstream>  // string to number conversion
//#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
//#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
//#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
//#include <opencv2/opencv.hpp>
//
//using namespace cv;
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
//int main(int argc, char *argv[])
//{
////    int delay = 1;
//    char c;
////    int frameNum = -1;          // Frame counter
//    bool lastImgHasHand=false;
//    
//    int previousX=0;
//    int previousY=0;
//    CvCapture* pCapture = NULL;//
//    pCapture = cvCreateCameraCapture(CV_CAP_ANY);
//    
//    //Size refS = Size( (int) captRefrnc.get(CV_CAP_PROP_FRAME_WIDTH),
//    //  (int) captRefrnc.get(CV_CAP_PROP_FRAME_HEIGHT) );
//    
////    bool bHandFlag = false;
//    
//    const char* WIN_SRC = "Source";
//    const char* WIN_RESULT = "Result";
//    
//    // Windows
//    namedWindow(WIN_SRC, CV_WINDOW_AUTOSIZE );
//    namedWindow(WIN_RESULT, CV_WINDOW_AUTOSIZE);
//    
//    Mat frame;  // 输入视频帧序列
//    Mat frameHSV;   // hsv空间
//    Mat mask(frame.rows, frame.cols, CV_8UC1);  // 2值掩膜
//    Mat dst(frame); // 输出图像
//    
//    //  Mat frameSplit[4];
//
//    vector< vector<Point> > contours;   // 轮廓
//    vector< vector<Point> > filterContours; // 筛选后的轮廓
//    vector< Vec4i > hierarchy;    // 轮廓的结构信息
//    vector< Point > hull; // 凸包络的点集
//    
////    bool movement=false;
//    int count=0;
//    
//    int presentX=0;
//    int presentY=0;
//    
//    while(true) //Show the image captured in the window and repeat
//    {
//        //captRefrnc >> frame;
//        int minX=320;//屏幕的一半
//        int maxX=240;
//        int minY=320;
//        int maxY=240;
//        
//        frame = cvQueryFrame( pCapture );
//        if( frame.empty() )
//        {
//            cout << "摄像头打开失败！！！";
//            break;
//        }
//        // imshow用于显示矩阵类型的数据，不同于cvShowIamge
//        imshow( WIN_SRC, frame);
//        
//        // 中值滤波，去除椒盐噪声（因为其明显优于邻域平均法）
//        medianBlur(frame, frame, 5);
//        
//        // 将从摄像头获得到的RGB图像转换到HSV（也可以考虑将图像转换到YCbCr空间来进行处理）
//        cvtColor( frame, frameHSV, CV_BGR2HSV );
//        
//        Mat dstTemp1(frame.rows, frame.cols, CV_8UC1);
//        Mat dstTemp2(frame.rows, frame.cols, CV_8UC1);
//        
//        // 对HSV空间进行量化，得到2值图像，亮的部分为手的形状
//        // inRange(InputArray src, InputArray lowerb, InputArray upperb, OutputArray dst)
//        // 第一个参数是指输入的图像，第二个和第三个参数是阈值范围的上界和下界，第四个参数是输出的图像
//        // HSV空间选取 0.1<H<0.15; 0.2<S<0.6; V>0.15时实现效果最好（以上原程序中的参数实现效果没有这个好）
//        inRange(frameHSV, Scalar(2.56,51.2,38.4), Scalar(38.4,153.6,256), dstTemp1);
////        inRange(frameHSV, Scalar(0,30,30), Scalar(40,170,256), dstTemp1);   //原始程序
//        inRange(frameHSV, Scalar(156,30,30), Scalar(180,170,256), dstTemp2);
//        
//        // bitwise_or：是将两张图像进行或操作（看一下HSV肤色模型）
//        bitwise_or(dstTemp1, dstTemp2, mask);
////        inRange(frameHSV, Scalar(0,30,30), Scalar(180,170,256), dst);
////        inRange(frameHSV, Scalar(2.56,51.2,38.4), Scalar(38.4,153.6,256), mask);  //直接将
//        
//        // 形态学操作，去除噪声，并使手的边界更加清晰（可以分析是放在后面还是前面好）
//        // getStructuringElement(int shape, Size ksize)
//        // 可以获取常用的结构元素的形状：矩形（包括线形）MORPH_RECT、椭圆（包括圆形）MORPH_ELLIPSE、十字形MORPH_CROSS；
//        // 第二个参数是结构元素的大小及形状,这个函数与morphologyEx一起使用用于定义核
//        Mat element = getStructuringElement(MORPH_RECT, Size(3,3));
//        
//        // 对目标物体先腐蚀再膨胀形成一次开运算，一般用于去掉目标区域的突出物；先膨胀再腐蚀形成一次闭运算，一般用于消除鸿沟或小的孔洞
//        //（此处可以考虑进行两种运算对于实验结果的影响）
//        
//        // 腐蚀操作
//        // erode(mask, mask, element);
//        
//        // morphologyEx(InputArray src, OutputArray dst, int op, InputArray kernel)在getStructuringElement定义的核的基础上进行形态学的操作
//        // 前两个参数是输入输出图像，第三个参数，int类型的op，表示形态学运算的类型：
//        // MORPH_OPEN-开运算；MORPH_CLOSE-闭运算；MORPH_GRADIENT-形态学梯度；MORPH_TOPHAT-“顶帽”;MORPH_BLACKHAT-“黑帽”
//        // 第四个参数，InputArray类型的kernel，形态学运算的内核。若为NULL时，表示的是使用参考点位于中心3x3的核。一般使用函数 getStructuringElement配合这个参数的使用。
//        morphologyEx(mask, mask, MORPH_OPEN, element);
//        
//        // 膨胀操作
//        dilate(mask, mask, element);
//        
//        // 这一步执行了闭运算，相当于先执行了一次腐蚀操作，然后是开运算，接着膨胀操作，最后又执行了一次闭运算（考虑一下怎样排列这些操作可以实现最好的效果）
//        morphologyEx(mask, mask, MORPH_CLOSE, element);
//        
//        // 作用是把mask和dst重叠以后把mask中像素值为0（black）的点对应的dst中的点变为透明，而保留其他点。
//        frame.copyTo(dst, mask);
//        contours.clear();
//        hierarchy.clear();
//        filterContours.clear();
//        
////        // 二值化图像
////        // 将mat类型转化为IplImage类型
////        IplImage pSrcImage = dst;
////        
////        // 转为灰度图
////        g_pGrayImage =  cvCreateImage(cvGetSize(&pSrcImage), IPL_DEPTH_8U, 1);
////        cvCvtColor(&pSrcImage, g_pGrayImage, CV_BGR2GRAY);
////        
////        // 创建二值图
////        g_pBinaryImage = cvCreateImage(cvGetSize(g_pGrayImage), IPL_DEPTH_8U, 1);
////        
////        // 显示原图
////        cvNamedWindow(pstrWindowsSrcTitle, CV_WINDOW_AUTOSIZE);
////        cvShowImage(pstrWindowsSrcTitle, &pSrcImage);
////        // 创建二值图窗口
////        cvNamedWindow(pstrWindowsBinaryTitle, CV_WINDOW_AUTOSIZE);
////        
////        // 滑动条
////        int nThreshold = 0;
////        cvCreateTrackbar(pstrWindowsToolBarName, pstrWindowsBinaryTitle, &nThreshold, 254, on_trackbar);
////        
////        on_trackbar(1);
//
//        cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
//        imshow("test", mask);
//
//        // 得到手的轮廓
//        findContours(mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
//        
//        // 去除伪轮廓
//        for (size_t i = 0; i < contours.size(); i++)
//        {
//            //  approxPolyDP(Mat(contours[i]), Mat(approxContours[i]), arcLength(Mat(contours[i]), true)*0.02, true);
//            if (fabs(contourArea(Mat(contours[i]))) > 30000) //判断手进入区域的阈值
//            {
//                filterContours.push_back(contours[i]);
//            }
//        }
//        // 画轮廓
//        if(filterContours.size()>0)
//        {
//            
//            count++;
//            lastImgHasHand=true;
//            drawContours(dst, filterContours, -1, Scalar(255,0,255), 3/*, 8, hierarchy*/);
//            
//            for (size_t j=0; j<filterContours.size(); j++)
//            {
//                convexHull(Mat(filterContours[j]), hull, true);
//                int hullcount = (int)hull.size();
//                for (int i=0; i<hullcount-1; i++)
//                {
//                    line(dst, hull[i+1], hull[i], Scalar(255,255,255), 2, CV_AA);//白色
//                    printf("num%d:x=%d\ty=%d\t\n",i,hull[i].x,hull[i].y);
//                    if(hull[i].x>maxX)
//                        maxX=hull[i].x;
//                    if(hull[i].x<minX)
//                        minX=hull[i].x;
//                    if(hull[i].y>maxY)
//                        maxY=hull[i].y;
//                    if(hull[i].y<minY)
//                        minY=hull[i].y;
//                    printf("miniX=%d\tminiY=%d\tmaxX=%d\tmaxY=%d\t\n",minX,minY,maxX,maxY);
//                    
//                }
//                
//                line(dst, hull[hullcount-1], hull[0], Scalar(0,255,0), 2, CV_AA);//绿色，最后一条
//                
//                if(count==1)//第一个轮廓的中心位置存在全局变量中，到最后一个再跟它比。
//                {
//                    previousX=(minX+maxX)/2;
//                    printf("previousX=%d\n",previousX);
//                    previousY=(minY+maxY)/2;
//                    printf("previousY=%d\n",previousY);
//                }
//                else
//                {
//                    presentX=(minX+maxY)/2;
//                    presentY=(minY+maxY)/2;
//                }
//            }
//        }
//        else
//        {
//            if(lastImgHasHand==true)
//            {
//                if((previousX-presentX)<0)//中文的大括号和英文的大括号用肉眼看不出来，坑啊
//                {
//                    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<left\n");//镜像，没有flip过来，所以这里注意点。
////                    keybd_event(VK_LEFT,(BYTE)0, 0 ,0);
////                    keybd_event(VK_LEFT, (BYTE)0, KEYEVENTF_KEYUP,0);
//                }
//                if((previousX-presentX)>0)
//                {
//                    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>right\n");
////                    keybd_event(VK_RIGHT,(BYTE)0, 0 ,0);
////                    keybd_event(VK_RIGHT, (BYTE)0, KEYEVENTF_KEYUP,0);
//                }
//                if((previousY-presentY)<0)
//                {
//                    printf("downVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n");
//                }
//                if((previousY-presentY)>0)
//                {
//                    printf("upAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa\n");
//                }
//                
//                count=0;
//                lastImgHasHand=false;
//            }
//        }
//        
//        imshow(WIN_RESULT, dst);
//        dst.release();
//        cvDestroyWindow(pstrWindowsBinaryTitle);
////        cvReleaseImage(&pSrcImage);
//        cvReleaseImage(&g_pGrayImage);
//        cvReleaseImage(&g_pBinaryImage);
//        
////        printf("previousX=%d\tpresentX=%d\tpreviousY=%d\tpresentY=%d\n",previousX,presentX,previousY,presentY);
////        printf("count=%d\n",count);
//        // End
//        c = cvWaitKey(1);
//        if (c == 27)
//            break;  
//    }
//    return 0;
//}
