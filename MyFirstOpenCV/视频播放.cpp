//
//  视频播放.cpp
//  MyFirstOpenCV
//
//  Created by 张才明 on 2017/3/30.
//  Copyright © 2017年 CCNU. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

//int main(int argc, char** argv){
//    const char* aviPath = "/Users/Camlin_Z/Downloads/myVideo.mp4";
//    cvNamedWindow("camlin", CV_WINDOW_AUTOSIZE);
//    //通过参数确定要读入的视频文件，返回一个指向CvCapture的指针
//    CvCapture* capture = cvCreateFileCapture(aviPath);
//    //初始化一个IplImage结构体用于存放视频文件的每一帧图像
//    IplImage* frame;
//    //开始读入视频文件
//    while (1) {
//        //装载下一帧的视频文件至内存，返回当前帧的指针，与cvLoadImage(imgPath)不同的是cvQueryFrame(capture)
//        //已经在CvCapture中分配好了内存，所以不需要通过cvReleaseImage( &img )释放每个图片对应的内存
//        frame = cvQueryFrame(capture);
//        if (!frame) break;
//        //将每一帧图片显示到之前新建的窗口中
//        cvShowImage("camlin", frame);
//        //当帧显示后等待2000ms，如果其间用户触发了一个按键，c就被设置成这个按键的ASCII码，否则则被设置成-1。
//        //如果用户触发了ESC键(ASCII码为27)，则退出循环。
//        char c = cvWaitKey(2000);
//        if (c == 27) {
//            break;
//        }
//    }
//    //释放CvCapture结构开辟的内存空间，这同时也会关闭所有打开的AVI文件相关的文件句柄
//    cvReleaseCapture(&capture);
//    cvDestroyWindow("camlin");
//}


//int main(int argc,char* argv[])
//{
//    cvNamedWindow("avi");
//    CvCapture* capture = cvCreateFileCapture("/Users/Camlin_Z/Downloads/myVideo.mp4");
//    IplImage* frame;
//    
//    while(1)
//    {
//        frame = cvQueryFrame(capture);
//        if(!frame) break ;
//        
//        cvShowImage("avi",frame);
//        char c = cvWaitKey(15);
//        if(c == 27)
//            break;
//    }
//    cvReleaseCapture(&capture);
//    
//    cvDestroyWindow( "avi");
//    return 0;
//}
