////
////  调用摄像头.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/5/6.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//
//int main(int argc, char* argv[])
//{
//    cvNamedWindow("Camera" , CV_WINDOW_AUTOSIZE );
//    CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY);
//    IplImage *frame;
//    while(1)
//    {
//        //抓取视频的每一帧图像
//        frame = cvQueryFrame(capture);
//        if(!frame) break;
//        cvShowImage("Camera",frame);
//        char c = cvWaitKey(15);
//        if(c == 27)  break;
//    }
//    cvReleaseImage(&frame);
//    cvDestroyWindow("Camera");
//    return 0;
//}
