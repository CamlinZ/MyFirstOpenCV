//
//  灰度化视频文件.cpp
//  MyFirstOpenCV
//
//  Created by 张才明 on 2017/4/7.
//  Copyright © 2017年 CCNU. All rights reserved.
//

//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>

//int main(int argc, char* argv[]){
//    CvCapture* capture = 0;
//    capture = cvCreateFileCapture("/Users/Camlin_Z/Movies/【lol电影天堂www.loldytt.com】行尸走肉.The.Walking.Dead.S07E13.中英字幕.HDTVrip.720P.mp4");
//    if (!capture) {
//        return -1;
//    }
//    //初始化视频
//    IplImage *bgr_frame = cvQueryFrame(capture);
//    double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
//    CvSize size = cvSize(
//        (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
//        (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
//    );
//    CvVideoWriter* writer = cvCreateVideoWriter("camlin", CV_FOURCC('M','J','P','G'), fps, size);
//    IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);
//    while ((bgr_frame = cvQueryFrame(capture)) != NULL) {
//        cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame ->width/2, bgr_frame ->height/2), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
//        cvWriteFrame(writer, logpolar_frame);
//    }
//    cvReleaseVideoWriter(&writer);
//    cvReleaseImage(&logpolar_frame);
//    cvReleaseCapture(&capture);
//    return 0;
//}
