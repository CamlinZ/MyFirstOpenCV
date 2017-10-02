//
//  process.h
//  MyFirstOpenCV
//
//  Created by 张才明 on 2017/5/6.
//  Copyright © 2017年 CCNU. All rights reserved.
//

#ifndef process_h
#define process_h


#endif /* process_h */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

void init_hand_YCrCb();
void hand_YCrCb();
void init_hand_HSV();
void color_blance();
void hand_HSV();
void inti_threshold();
void threshold();
void resizeSrc();
void reduce_noise();
void hand_contours(IplImage* dst);
void init_hand_template();
void hand_template_match(CvSeq* handT, CvSeq* hand);
void init_laplace();
void toLaplace(IplImage* dst);
void hand_direction(CvSeq* hand);
void hand_draw(IplImage* dst, CvSeq* hands);
void resizeAllWindow();
void sharpenImage1(const cv::Mat &image, cv::Mat &result);
