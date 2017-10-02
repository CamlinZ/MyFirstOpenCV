//
////  摄像头读入图像后的边缘分析代码.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/3/30.
////  Copyright © 2017年 CCNU. All rights reserved.
//
//
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//
//
//using namespace std;
//using namespace cv;
//
////定义的doCanny中的参数就是与cvCanny中的参数相互对应的
//IplImage* doCanny(IplImage* image_input,double lowThresh,double highThresh,double aperture)
//{
//    //如果输入的图像不是单通道图像则返回0
//    if(image_input->nChannels != 1)
//        return (0);
//    
//    //初始化输出图像
//    IplImage* image_output = cvCreateImage(cvGetSize(image_input),image_input->depth,image_input->nChannels);
//    
//    //cvCanny(const CvArr* image,CvArr* edges,double threshold1,double threshold2,int aperture_size=3)
//    //该函数为使用CANNY算法来提取图像边缘，第一个参数是单通道输入图像，第二个参数是单通道边缘输出图像，第三个和第四个参数分别是两个阈值，前一个小的用来控制边缘连接，
//    //后一个大的用来控制强边缘的初始分割。需要注意的是该函数只接受单通道图像作为输入。
//    cvCanny(image_input,image_output,lowThresh,highThresh,aperture);
//    return(image_output);
//}
//
//int main(int argc, char* argv[])
//{
//    cvNamedWindow("Camera" , CV_WINDOW_AUTOSIZE );
//    CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY);
//    //assert的作用是现计算表达式expression,如果其值为假（即为0),那么它先向stderr打印一条出错信息,然后通过调用abort来终止程序运行。
//    assert(capture != NULL);
//    IplImage *frame;
//    frame = cvQueryFrame(capture);
//    //cvCreateImage(CvSize size,int depth,int channels)用于创建首地址并分配存储空间，第一个参数是图像的大小，第二个参数是位深度，下面的参数
//    //IPL_DEPTH_8U是指无符号8位整型，第三个参数是指每个像素的通道数
//    IplImage *frame_edge = cvCreateImage(cvGetSize(frame),IPL_DEPTH_8U,1);
//    
//    while(1)
//    {
//        //抓取视频的每一帧图像
//        frame = cvQueryFrame(capture);
//        if(!frame) break;
//        //cvConvertImage(const CvArr* src,CvArr*dst,int flags CV_DEFAULT(0))中第一个参数是指原图像的指针，第二个参数是指转换后的图像的指针，
//        //第三个参数是指转换的模式，0指没有变化，1指垂直翻转，2指交换红蓝通道
//        cvConvertImage(frame,frame_edge,0);
//        //将frame_edge复制到frame中
//        frame = cvCloneImage(frame_edge);
//        frame_edge = doCanny(frame_edge,70,90,3);
//        cvShowImage("Camera",frame_edge);
//        char c = cvWaitKey(15);
//        if(c == 27)  break;
//    }
//    
//    cvReleaseCapture(&capture);
//    cvReleaseImage(&frame_edge);
//    cvReleaseImage(&frame);
//    return 0;
//}
