//
//  detectFeatures.cpp
//  MyFirstOpenCV
//
//  Created by 张才明 on 2017/7/17.
//  Copyright © 2017年 CCNU. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include "slamBase.h"
using namespace std;

// OpenCV 特征检测模块
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/calib3d/calib3d.hpp>

int main( int argc, char** argv )
{
    
//#################### 特征的检测与描述子的计算 ###################
    
    // 声明并从data文件夹里读取两个rgb与深度图
    cv::Mat rgb1 = cv::imread( "/Users/Camlin_Z/资料/毕业论文/rgb1.png");
    cv::Mat rgb2 = cv::imread( "/Users/Camlin_Z/资料/毕业论文/rgb2.png");
    cv::Mat depth1 = cv::imread( "/Users/Camlin_Z/资料/毕业论文/depth1.png", -1);
    //cv::Mat depth2 = cv::imread( "/Users/Camlin_Z/资料/毕业论文/depth2.png", -1);
    
    // 要在一个图像里提取特征，第一步是计算“关键点”，然后，针对这些关键点周围的像素，计算其“描述子”
    // 在OpenCV中，分别由cv::FeatureDetector和cv::DescriptorExtractor来计算
    // 然后使用 _detector->detect()函数提取关键点,_detector和_descriptor的类型可以由字符串指定
    // 声明特征提取器与描述子提取器
    cv::Ptr<cv::FeatureDetector> _detector;
    cv::Ptr<cv::DescriptorExtractor> _descriptor;
    
    // 构建提取器，默认两者都为sift
    // 构建sift, surf之前要初始化nonfree模块
    cv::initModule_nonfree();
    // 如果想构建FAST, SURF等特征，只需改后面的字符串即可
    _detector = cv::FeatureDetector::create( "GridSIFT" );
    _descriptor = cv::DescriptorExtractor::create( "SIFT" );
    
    vector< cv::KeyPoint > kp1, kp2; //关键点
    _detector->detect( rgb1, kp1 );  //提取关键点
    _detector->detect( rgb2, kp2 );
    
    cout<<"Key points of two images: "<<kp1.size()<<", "<<kp2.size()<<endl;
    
    // 可视化，显示关键点
    cv::Mat imgShow;
    cv::drawKeypoints( rgb1, kp1, imgShow, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
    cv::imshow( "keypoints", imgShow );
    cv::imwrite( "/Users/Camlin_Z/资料/毕业论文/keypoints.png", imgShow );
    cv::waitKey(0); //暂停等待一个按键
    
//######################## 特征匹配 #######################
    
    // 计算描述子
    cv::Mat desp1, desp2;
    _descriptor->compute( rgb1, kp1, desp1 );
    _descriptor->compute( rgb2, kp2, desp2 );
    
    // 匹配描述子(需要选择一个匹配算法，此处选择近似最邻近FLANN)
    // 匹配完成后，算法会返回一些 DMatch 结构。该结构含有以下几个成员：
    // queryIdx 源特征描述子的索引（也就是第一张图像）。
    // trainIdx 目标特征描述子的索引（第二个图像）。
    // distance 匹配距离，越大表示匹配越差。
    vector< cv::DMatch > matches;
    cv::FlannBasedMatcher matcher;
    matcher.match( desp1, desp2, matches );
    cout<<"Find total "<<matches.size()<<" matches."<<endl;
    
    // 可视化：显示匹配的特征
    cv::Mat imgMatches;
    cv::drawMatches( rgb1, kp1, rgb2, kp2, matches, imgMatches );
    cv::imshow( "matches", imgMatches );
    cv::imwrite( "/Users/Camlin_Z/资料/毕业论文/matches.png", imgMatches );
    cv::waitKey( 0 );
    
    // 筛选匹配，把距离太大的去掉
    // 这里使用的准则是去掉大于四倍最小距离的匹配(经验数值)
    vector< cv::DMatch > goodMatches;
    double minDis = 9999;
    // 选择图像中所有匹配的距离最小值
    for ( size_t i=0; i<matches.size(); i++ )
    {
        if ( matches[i].distance < minDis )
            minDis = matches[i].distance;
    }
    // 去掉距离大于四倍的匹配而选出有用的匹配
    for ( size_t i=0; i<matches.size(); i++ )
    {
        if (matches[i].distance < 4*minDis)
            goodMatches.push_back( matches[i] );
    }
    
    // 显示 good matches
    cout<<"good matches="<<goodMatches.size()<<endl;
    cv::drawMatches( rgb1, kp1, rgb2, kp2, goodMatches, imgMatches );
    cv::imshow( "good matches", imgMatches );
    cv::imwrite( "/Users/Camlin_Z/资料/毕业论文/good_matches.png", imgMatches );
    cv::waitKey(0);
    
    // 计算图像间的运动关系
    // 关键函数：cv::solvePnPRansac()
    // 为调用此函数准备必要的参数
    
    // 第一个帧的三维点
    vector<cv::Point3f> pts_obj;
    // 第二个帧的图像点
    vector< cv::Point2f > pts_img;
    
    // 相机内参
    CAMERA_INTRINSIC_PARAMETERS C;
    C.cx = 325.5;
    C.cy = 253.5;
    C.fx = 518.0;
    C.fy = 519.0;
    C.scale = 1000.0;
    
    for (size_t i=0; i<goodMatches.size(); i++)
    {
        // query 是第一个, train 是第二个
        cv::Point2f p = kp1[goodMatches[i].queryIdx].pt;
        // 获取d是要小心！x是向右的，y是向下的，所以y才是行，x是列！
        ushort d = depth1.ptr<ushort>( int(p.y) )[ int(p.x) ];
        if (d == 0)
            continue;
        pts_img.push_back( cv::Point2f( kp2[goodMatches[i].trainIdx].pt ) );
        
        // 将(u,v,d)转成(x,y,z)
        cv::Point3f pt ( p.x, p.y, d );
        cv::Point3f pd = point2dTo3d( pt, C );
        pts_obj.push_back( pd );
    }
    
    double camera_matrix_data[3][3] = {
        {C.fx, 0, C.cx},
        {0, C.fy, C.cy},
        {0, 0, 1}
    };
    
    // 构建相机矩阵
    cv::Mat cameraMatrix( 3, 3, CV_64F, camera_matrix_data );
    cv::Mat rvec, tvec, inliers;
    // 求解pnp
    cv::solvePnPRansac( pts_obj, pts_img, cameraMatrix, cv::Mat(), rvec, tvec, false, 100, 1.0, 100, inliers );
    
    cout<<"inliers: "<<inliers.rows<<endl;
    cout<<"R="<<rvec<<endl;
    cout<<"t="<<tvec<<endl;
    
    // 画出inliers匹配
    vector< cv::DMatch > matchesShow;
    for (size_t i=0; i<inliers.rows; i++)
    {
        matchesShow.push_back( goodMatches[inliers.ptr<int>(i)[0]] );
    }
    cv::drawMatches( rgb1, kp1, rgb2, kp2, matchesShow, imgMatches );
    cv::imshow( "inlier matches", imgMatches );
    cv::imwrite( "/Users/Camlin_Z/资料/毕业论文/inliers.png", imgMatches );
    cv::waitKey( 0 );
    
    return 0;
}
