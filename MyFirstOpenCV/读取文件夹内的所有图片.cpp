////
////  读取文件夹内的所有图片.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/5/18.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include "opencv2/opencv.hpp"
//#include "iostream"
//
//using namespace std;
//using namespace cv;
//
//#define NUM 50     //读取image的个数
//int main()
//{
//    Mat image;
//    string ImgName;
//    int n = 1;
//    while(n <= NUM)
//    {
//        //int 转换string
//        stringstream ss;
//        string str;
//        ss<<n;
//        ss>>str;
//        
//        ImgName = str;    //图像文件明格式：ImgName(n)
//        ImgName = "/Users/Camlin_Z/Downloads/Gesture/" + ImgName+".bmp";
//        cout<<"处理："<<ImgName<<endl;
//        image= imread(ImgName);//读取图片
//        if(image.data ==0)
//        { printf("[error] 没有图片\n");}
//        n++;
//    }
//    
//    waitKey(0);
//    system("pause");
//    return 3;
//}
