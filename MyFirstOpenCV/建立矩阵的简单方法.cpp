////
////  建立矩阵的简单方法.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/4/7.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//
//float sum(const CvMat* mat){
//    float s = 0.0f;
//    for(int row=0; row<mat->rows; row++){
//        const float* ptr = (const float*)(mat->data.ptr + row* mat->step);
//        for (int col=0; col<mat->cols; col++) {
//            s += *ptr++;
//        }
//    }
//return(s);
//}
//
//using namespace std;
//int main(int argc, char* argv[]){
//    CvMat* mat = cvCreateMat( 5 , 5, CV_32FC1);
//    //    float element_3_2 = CV_MAT_ELEM(*mat, float, 3, 2);
//    float element_3_2 = 7.7;
//    *((float*)CV_MAT_ELEM_PTR(*mat, 3, 2)) = element_3_2;
//    float element = CV_MAT_ELEM(*mat, float, 4, 2);
//    cout<<element<<endl;
//    cout<<sum(mat)<<endl;
//}
