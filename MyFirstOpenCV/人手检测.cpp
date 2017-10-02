////
////  人手检测.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/5/18.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <list>
//#include <map>
//#include <stack>
//#include <opencv2/core/core.hpp>
//#include <opencv2/features2d/features2d.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/calib3d/calib3d.hpp>
//
//using namespace std;
//using namespace cv;
//
//
////8邻接种子算法，并返回每块区域的边缘框
//void Seed_Filling(const cv::Mat& binImg, cv::Mat& labelImg, int& labelNum, int (&ymin)[20], int(&ymax)[20], int(&xmin)[20], int(&xmax)[20])   //种子填充法
//{
//    if (binImg.empty() ||
//        binImg.type() != CV_8UC1)
//    {
//        return;
//    }
//    
//    labelImg.release();
//    binImg.convertTo(labelImg, CV_32SC1);
//    int label = 1;
//    int rows = binImg.rows - 1;
//    int cols = binImg.cols - 1;
//    for (int i = 1; i < rows - 1; i++)
//    {
//        int* data = labelImg.ptr<int>(i);
//        for (int j = 1; j < cols - 1; j++)
//        {
//            if (data[j] == 1)
//            {
//                std::stack<std::pair<int, int>> neighborPixels;
//                neighborPixels.push(std::pair<int, int>(j, i));     // 像素位置: <j,i>
//                ++label;  // 没有重复的团，开始新的标签
//                ymin[label] = i;
//                ymax[label] = i;
//                xmin[label] = j;
//                xmax[label] = j;
//                while (!neighborPixels.empty())
//                {
//                    std::pair<int, int> curPixel = neighborPixels.top(); //如果与上一行中一个团有重合区域，则将上一行的那个团的标号赋给它
//                    int curX = curPixel.first;
//                    int curY = curPixel.second;
//                    labelImg.at<int>(curY,curX) = label;
//                    
//                    neighborPixels.pop();
//                    
//                    if ((curX>0)&&(curY>0)&&(curX<(cols-1))&&(curY<(rows-1)))
//                    {
//                        if (labelImg.at<int>(curY - 1,curX) == 1)                     //上
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX, curY - 1));
//                            //ymin[label] = curY - 1;
//                        }
//                        if (labelImg.at<int>( curY + 1,curX) == 1)                    //下
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX, curY + 1));
//                            if ((curY+1)>ymax[label])
//                                ymax[label] = curY + 1;
//                        }
//                        if (labelImg.at<int>(curY,curX - 1) == 1)                     //左
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX - 1, curY));
//                            if ((curX - 1)<xmin[label])
//                                xmin[label] = curX - 1;
//                        }
//                        if (labelImg.at<int>(curY,curX + 1) == 1)                     //右
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX + 1, curY));
//                            if ((curX + 1)>xmax[label])
//                                xmax[label] = curX + 1;
//                        }
//                        if (labelImg.at<int>(curY - 1,curX-1) == 1)                   //左上
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX - 1, curY - 1));
//                            //ymin[label] = curY - 1;
//                            if ((curX - 1)<xmin[label])
//                                xmin[label] = curX - 1;
//                        }
//                        if (labelImg.at<int>(curY + 1,curX+1) == 1)                   //右下
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX+1, curY + 1));
//                            if ((curY + 1)>ymax[label])
//                                ymax[label] = curY + 1;
//                            if ((curX + 1)>xmax[label])
//                                xmax[label] = curX + 1;
//                            
//                        }
//                        if (labelImg.at<int>( curY + 1,curX - 1) == 1)                    //左下
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX - 1, curY+1));
//                            if ((curY + 1)>ymax[label])
//                                ymax[label] = curY + 1;
//                            if ((curX - 1)<xmin[label])
//                                xmin[label] = curX - 1;
//                        }
//                        if (labelImg.at<int>( curY - 1,curX + 1) == 1)                    //右上
//                        {
//                            neighborPixels.push(std::pair<int, int>(curX + 1, curY-1));
//                            //ymin[label] = curY - 1;
//                            if ((curX + 1)>xmax[label])
//                                xmax[label] = curX + 1;
//                            
//                        }
//                    }
//                }
//            }
//        }
//    }
//    labelNum = label-1;    
//}
//
//class WatershedSegmenter {
//private:
//    cv::Mat markers;
//public:
//    void setMarkers(const cv::Mat& markerImage) {
//        
//        // Convert to image of ints
//        markerImage.convertTo(markers, CV_32S);
//    }
//    cv::Mat process(const cv::Mat &image) {
//        
//        // Apply watershed
//        cv::watershed(image, markers);
//        return markers;
//    }
//    // Return result in the form of an image
//    cv::Mat getSegmentation() {
//        
//        cv::Mat tmp;
//        // all segment with label higher than 255
//        // will be assigned value 255
//        markers.convertTo(tmp, CV_8U);
//        return tmp;
//    }
//    
//    // Return watershed in the form of an image
//    cv::Mat getWatersheds() {
//        cv::Mat tmp;
//        markers.convertTo(tmp, CV_8U,255, 255);
//        return tmp;
//    }
//};
//
//
//
//
//
//int main()
//{
//    //设置视频读入，括号里面的数字是摄像头的选择，一般自带的是0
//    cv::VideoCapture cap(0);
//    if (!cap.isOpened())
//    {
//        return -1;
//    }
//    Mat frame;
//    Mat binImage,tmp;
//    Mat Y, Cr, Cb;
//    vector<Mat> channels;
//    //模板图片，是Cr颜色通道的人手图像截图
//    Mat tmpl = imread("/Users/Camlin_Z/Downloads/12345.png",CV_8UC1);
//    
//    bool stop = false;
//    while (!stop)
//    {
//        //读入视频帧，转换颜色空间，并分割通道
//        cap >> frame;
//        cvtColor(frame, binImage, CV_BGR2GRAY);
//        frame.copyTo(tmp);
//        cvtColor(tmp, tmp, CV_BGR2YCrCb);
//        split(tmp, channels);
//        Cr = channels.at(1);
//        Cb = channels.at(2);
//        
//        //肤色检测，输出二值图像
//        for (int j = 1; j < Cr.rows - 1; j++)
//        {
//            uchar* currentCr = Cr.ptr< uchar>(j);
//            uchar* currentCb = Cb.ptr< uchar>(j);
//            uchar* current = binImage.ptr< uchar>(j);
//            for (int i = 1; i < Cb.cols - 1; i++)
//            {
//                if ((currentCr[i] > 140) && (currentCr[i] < 170)  &&(currentCb[i] > 77) && (currentCb[i] < 123))
//                    current[i] = 255;
//                else
//                    current[i] = 0;
//            }
//        }
//        
//        //形态学处理
//        //dilate(binImage, binImage, Mat());
//        dilate(binImage, binImage, Mat());
//        
//        //分水岭算法
//        cv::Mat fg;
//        cv::erode(binImage, fg, cv::Mat(), cv::Point(-1, -1), 6);
//        // Identify image pixels without objects
//        cv::Mat bg;
//        cv::dilate(binImage, bg, cv::Mat(), cv::Point(-1, -1), 6);
//        cv::threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);
//        // Show markers image
//        cv::Mat markers(binImage.size(), CV_8U, cv::Scalar(0));
//        markers = fg + bg;
//        // Create watershed segmentation object
//        WatershedSegmenter segmenter;
//        segmenter.setMarkers(markers);
//        segmenter.process(frame);
//        Mat waterShed;
//        waterShed = segmenter.getWatersheds();
//        //imshow("watershed", waterShed);
//        //获得区域边框
//        threshold(waterShed, waterShed, 1, 1, THRESH_BINARY_INV);
//        
//        //8向种子算法，给边框做标记
//        Mat labelImg;
//        int label, ymin[20], ymax[20], xmin[20], xmax[20];
//        Seed_Filling(waterShed, labelImg, label, ymin, ymax, xmin, xmax);
//
//        //根据标记，对每块候选区就行缩放，并与模板比较
//        Size dsize = Size(tmpl.cols, tmpl.rows);
//        float simi[20];
//        for (int i = 0; i < label; i++)
//        {
//            simi[i] = 1;
//            if (((xmax[2 + i] - xmin[2 + i])>50) && ((ymax[2 + i] - ymin[2 + i]) > 50))
//            {
//                //rectangle(frame, Point(xmin[2 + i], ymin[2 + i]), Point(xmax[2 + i], ymax[2 + i]), Scalar::all(255), 2, 8, 0);
//                Mat rROI = Mat(dsize, CV_8UC1);
//                resize(Cr(Rect(xmin[2 + i], ymin[2 + i], xmax[2 + i] - xmin[2 + i], ymax[2 + i] - ymin[2 + i])), rROI, dsize);
//                Mat result;
//                matchTemplate(rROI, tmpl, result, CV_TM_SQDIFF_NORMED);
//                simi[i] = result.ptr<float>(0)[0];
//                //cout << simi[i] << endl;
//            }
//        }
//        
//        
//        //统计一下区域中的肤色区域比例
//        float fuseratio[20];
//        for (int k = 0; k < label; k++)
//        {
//            fuseratio[k] = 1;
//            if (((xmax[2 + k] - xmin[2 + k])>50) && ((ymax[2 + k] - ymin[2 + k]) > 50))
//            {
//                int fusepoint=0;
//                for (int j = ymin[2+k]; j < ymax[2+k]; j++)
//                {
//                    uchar* current = binImage.ptr< uchar>(j);
//                    for (int i = xmin[2+k]; i < xmax[2+k]; i++)
//                    {
//                        if (current[i] == 255)
//                            fusepoint += 1;
//                    }
//                }
//                fuseratio[k] = float(fusepoint) / ((xmax[2 + k] - xmin[2 + k])*(ymax[2 + k] - ymin[2 + k]));
//                //cout << fuseratio[k] << endl;
//            }  
//        }  
//        
//        //给符合阈值条件的位置画框  
//        for (int i = 0; i < label; i++)  
//        {
//            
//            if ((simi[i]<0.02)&&(fuseratio[i]<0.53))
//                rectangle(frame, Point(xmin[2 + i], ymin[2 + i]), Point(xmax[2 + i], ymax[2 + i]), Scalar::all(255), 2, 8, 0);
//            
//        }  
//        
//        imshow("frame", frame);
//        //processor.writeNextFrame(frame);  
//        imshow("test", binImage);  
//        
//        if (waitKey(1) >= 0)  
//            stop = true;  
//    }  
//    cout << "ss" << endl;  
//    //cv::waitKey();  
//    return 0;  
//}
