////
////  显示图像.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/3/30.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//
////argc（argument count）指的输入参数的个数,argv指的命令行参数
//int main(int argc, char** argv){
//    const char* imgPath = "/Users/Camlin_Z/Downloads/1.JPG";
//    //将图片文件加载至内存并返回一个指针，其中IplImage结构体可以处理所有类型的图像文件
//    IplImage* img = cvLoadImage(imgPath);
//    //在屏幕上面创建一个窗口，第一个参数为窗口名字，第二个参数为0(窗口为默认大小)或者CV_WINDOW_AUTOSIZE(窗口大小随着图片大小变化)
//    cvNamedWindow("camlin", CV_WINDOW_AUTOSIZE);
//    //显示图像，第一个参数为确定在哪个已存在的窗口中显示图像，第二个参数为显示的图像指针对应的图像文件    
//    cvShowImage("camlin", img);
//    //使程序暂停，等待用户触发一个按键操作，当函数参数是一个正数的时候程序将暂停一段时间，时长为该整数值个毫秒单位，然后继续执行程序，
//    //即使用户没有按下任何按键；当设置该函数参数为0或者负数时，程序将一直等待用户出发按键操作
//    cvWaitKey(5000);
//    //该函数用于释放内存，参数指的释放该参数指向的内存块，执行完后该参数被设置为NULL
//    cvReleaseImage( &img );
//    //关闭窗口
//    cvDestroyWindow("camlin");
//}
