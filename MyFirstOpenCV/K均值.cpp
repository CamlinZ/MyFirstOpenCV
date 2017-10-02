////
////  K均值.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/4/10.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//
//int main(int argc, char** argv){
//    //K均值中的类别个数上界
//     #define MAX_CLUSTERS 5
//    
//    //CvScalar就是一个可以用来存放4个double数值的数组(是指数组中的每个元素都最多是四维的，而不是指只能存放四个元素)；一般用来存放像素值（不一定是灰度值）的，最多可以存放4个通道的。
//    CvScalar color_tab[MAX_CLUSTERS];
//    IplImage* img = cvCreateImage(cvSize(500, 500), 8, 3);
//    
//    //CvRNG用于存放cvRNG()生成的基本随机数，跟一般的C语言srand()使用方法一样，要先给它一个种子，但srand()用到的是unsigned int的32位种子范围，
//    //而cvRNG()用的是64位长整数种子。初始化CvRNG结构，假如seed给0，它将会自动转成-1。cvRNG(64位种子)
//    CvRNG rng = cvRNG(0xffffffff);
//    
//    //CV_RGB是OpenCV中的一个宏，用于创建一个色彩值
//    color_tab[0] = CV_RGB(255, 0, 0);
//    color_tab[1] = CV_RGB(0, 255, 0);
//    color_tab[2] = CV_RGB(100, 100, 255);
//    color_tab[3] = CV_RGB(255, 0, 255);
//    color_tab[4] = CV_RGB(255, 255, 0);
//    
//    cvNamedWindow("clusters", CV_WINDOW_AUTOSIZE);
//    
//    for (;;) {
//        //cvRandInt()返回均匀分布32位的随机数，均匀分布为统计学上的专有名词，表示长时间下所有数字出现的概率都是一样的，
//        //而cvRandint()在opencv里使用的公式temp = (uint64)(unsigned)temp*1554115554 + (temp >> 32);
//        //cluster_count是类别的个数，是随机产生的；sample_count是数据样本的个数，也是随机产生的(其中数据样本的上界是1000)。
//        int k, cluster_count = cvRandInt(&rng) % MAX_CLUSTERS + 1;
//        int i, sample_count = cvRandInt(&rng) % 1000 + 1;
//        
//        //机器学习的train()方法根据具体的算法呈现不同的形式。所有的算法都以一个指向CvMat矩阵的指针作为训练数据。
//        //矩阵必须是32FC1(32位浮点单通道)类型，CvMat结构可以支持多通道矩阵，但是机器学习只采用单通道矩阵
//        //points是一个浮点数双通道矩阵来存储sample_count个数据样本，clusters是一个整型矩阵，用来爱存储数据样本的聚类标签，范围是0~(cluster_count-1)，
//        //与cvKMeans2中lables参数对应
//        CvMat* points = cvCreateMat(sample_count, 1, CV_32FC2);
//        CvMat* clusters = cvCreateMat(sample_count, 1, CV_32SC1);
//        
//        //从多元高斯分布中产生随机样本
//        //给每个类别填写sample_count/cluster_count个数据样本，这些2维数据样本符合正态分布，正态分布的中心是随机选择的
//        for (k = 0; k < cluster_count; k++) {
//            CvPoint center;
//            CvMat point_chunk;
//            center.x = cvRandInt(&rng) % img->width;
//            center.y = cvRandInt(&rng) % img->height;
//            
//            //cvGetRows(const CvArr *arr, CvMat *submat, int start_row, int end_row):用于取出矩阵中的一些行。
//            //第一个参数是目标矩阵，第二个参数是矩阵指针，最后两个参数是开始和结束的行号，在运用OpenCV时，如果看到CvArr*，
//            //那么就可以传类型为CvMat或IplImage的数据类型进去，因为OpenCV中有如下的派生关系：派生关系：CvArr -> CvMat -> IplImage
//            cvGetRows(points, &point_chunk, k * sample_count/cluster_count,
//                      k == cluster_count - 1 ? sample_count : (k + 1) * sample_count/cluster_count);
//            
//            //cvRandArr(CvRNG *rng, CvArr *arr, int dist_type, CvScalar param1, CvScalar param2):用随机数填充数组，并更新RNG的状态,
//            //第一个参数arr为输出数组，第二个参数dist_type为分布类型：CV_RAND_UNI是均匀分布；CV_RAND_NORMAL是正态分布或者高斯分布，
//            //第三个参数param1是分布的第一个参数。如果是均匀分布它是随机数范围的闭下边界。如果是正态分布它是随机数的平均值。
//            //第四个参数param2是分布的第二个参数。如果是均匀分布它是随机数范围的开上边界。如果是正态分布它是随机数的标准差。
//            cvRandArr(&rng, &point_chunk, CV_RAND_NORMAL, cvScalar(center.x, center.y, 0, 0),
//                      cvScalar(img->width/6, img->height/6, 0, 0));
//        }
//        
//        //打乱数据样本的顺序
//        for (i = 0; i < sample_count/2; i++) {
//            //表示2通道的点，每通道由32位单精度浮点数表示
//            CvPoint2D32f* pt1 = (CvPoint2D32f*)points->data.fl + cvRandInt(&rng) % sample_count;
//            CvPoint2D32f* pt2 = (CvPoint2D32f*)points->data.fl + cvRandInt(&rng) % sample_count;
//            CvPoint2D32f temp;
//            
//            CV_SWAP(*pt1, *pt2, temp);
//        }
//        
//        //K均值聚类算法（使用该算法直到聚类中心的最大移动小于1）
//        //cvKMeans2(const CvArr *samples, int cluster_count, CvArr *labels, CvTermCriteria termcrit)
//        //samples:输入样本的浮点矩阵，每个样本一行，如对彩色图像进行聚类，每个通道一行，CV_32FC3；cluster_count:所给定的聚类数目；
//        //labels:输出整数向量,每个样本对应的类别标识，其范围为0~(cluster_count-1);termcrit:指定聚类的最大迭代次数和／或精度（两次迭代引起的聚类中心的移动距离），
//        //其执行 k-means 算法搜索 cluster_count 个类别的中心并对样本进行分类，输出 labels(i)为样本i的类别标识。其中CvTermCriteria为OpenCV中的迭代算法的终止准则。
//        cvKMeans2(points, cluster_count, clusters, cvTermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0));
//        
//        cvZero(img);
//        for (i = 0; i < sample_count; i++) {
//            CvPoint2D32f pt = ((CvPoint2D32f*)points->data.fl)[i];
//            int cluster_idx = clusters->data.i[i];
//            //cvCircle(CvArr *img, CvPoint center, int radius, CvScalar color):该函数用于绘制圆形，
//            //函数cvCircle绘制或填充一个给定圆心和半径的圆。圆被感兴趣矩形所裁剪。若指定圆的颜色，可以使用宏CV_RGB(r, g, b)。
//            //img 图像；center 圆心坐标；radius 圆形的半径；color 线条的颜色；thickness 如果是正数，表示组成圆的线条的粗细程度。否则，表示圆是否被填充；
//            //line_type线条的类型,见 cvLine 的描述；shift 圆心坐标点和半径值的小数点位数
//            cvCircle(img, cvPointFrom32f(pt), 2, color_tab[cluster_idx], CV_FILLED);
//        }
//        
//        cvReleaseMat(&points);
//        cvReleaseMat(&clusters);
//        
//        cvShowImage("clusters", img);
//        
//        int key = cvWaitKey(0);
//        if (key == 27) {
//            break;
//        }
//    }
//    return 0;
//}
