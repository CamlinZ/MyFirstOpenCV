//
//  视频播放进度条控制.cpp
//  MyFirstOpenCV
//
//  Created by 张才明 on 2017/3/30.
//  Copyright © 2017年 CCNU. All rights reserved.
//

//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>

//int g_slider_position = 0;
//CvCapture* g_capture = NULL;
//
//void onTrackbarSlider(int pos){
//    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
//}
//
//int main(int argc, char** argv){
//    cvNamedWindow("camlin", CV_WINDOW_AUTOSIZE);
//    g_capture = cvCreateFileCapture("/Users/Camlin_Z/Downloads/1.MOV");
//    int frames = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
//    if (frames!=0) {
//        cvCreateTrackbar("position", "camlin", &g_slider_position, frames, onTrackbarSlider);
//    }
//    IplImage* frame;
//    while (1) {
//        frame = cvQueryFrame(g_capture);
//        if (!frame) {
//            break;
//        }
//        cvShowImage("camlin", frame);
//        char c = cvWaitKey(33);
//        if (c == 27) {
//            break;
//        }
//    }
//    cvReleaseCapture(&g_capture);
//    cvDestroyWindow("camlin");
//    return 0;
//}
