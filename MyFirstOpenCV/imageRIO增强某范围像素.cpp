////
////  imageRIO增强某范围像素.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/4/9.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//
//using namespace std;
//int main(int argc, char** argv){
//    char* imgPath = "/Users/Camlin_Z/Downloads/1.JPG";
//    IplImage* src ;
//    if (argc == 7 && ((src = cvLoadImage(imgPath, 1)) != 0)) {
//        int x = atoi(argv[1]);
//        int y = atoi(argv[2]);
//        int width = atoi(argv[3]);
//        int height = atoi(argv[4]);
//        int add = atoi(argv[5]);
//        cvSetImageROI(src, cvRect(x, y, width, height));
//        cvAddS(src, cvScalar(add), src);
//        cvResetImageROI(src);
//        cvNamedWindow("Roi_Add", CV_WINDOW_AUTOSIZE);
//        cvShowImage("Roi_Add", src);
//        cvWaitKey();
//    }
//    return 0;
//}
