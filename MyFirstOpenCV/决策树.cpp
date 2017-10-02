////
////  决策树.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/4/12.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include "opencv2/core/core_c.h"
//#include "opencv2/ml/ml.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    //init data
//    float fdata[5][2] = {{1,1},{1,1},{1,0},{0,1},{0,1}};
//    Mat data(5,2,CV_32F,fdata);
//    float fresponses[5] ={1,1,0,0,0};
//    Mat responses(5,1,CV_32F,fresponses);
//    float priors[]={1,1};
//    CvDTree *tree;
//    CvDTreeParams params( 8, // max depth
//                         1, // min sample count
//                         0, // regression accuracy: N/A here
//                         true, // compute surrogate split, as we have missing data
//                         15, // max number of categories (use sub-optimal algorithm for larger numbers)
//                         0, // the number of cross-validation folds
//                         true, // use 1SE rule => smaller tree
//                         true, // throw away the pruned tree branches
//                         priors // the array of priors, the bigger p_weight, the more attention
//                         // to the poisonous mushrooms
//                         // (a mushroom will be judjed to be poisonous with bigger chance)
//                         );
//    tree = new CvDTree;
//    tree->train (data,CV_ROW_SAMPLE,responses,Mat(),Mat(),Mat(),Mat(),params);
//    //try predict
//    Mat sample(1,2,CV_32F,Scalar::all (1));
//    double r = tree->predict(sample,Mat())->value;
//    cout << "r: "<< r << endl;
//    //save tree in the xml file
//    tree->save("tree.xml","test_tree");
//    return 0;
//}
//
////int main(){
////    //初始化无毒和有毒蘑菇的权值
////    float priors[] = {1.0, 10.0};
////    float responses[2] = {112, 101};
////    CvMat* var_type;
////    Mat data(2, 1, CV_32F, priors);
//////    Mat responses(2,1,CV_32F,fresponses);
////    var_type = cvCreateMat( data.cols + 1, 1, CV_8U);
////    //所有这些变量都是绝对的
////    cvSet(var_type, cvScalarAll(CV_VAR_CATEGORICAL));
////    CvDTree* dtree;
////    dtree = new CvDTree;
////    //调用决策树的训练算法
////    dtree->train(data, CV_ROW_SAMPLE, responses, 0, 0, var_type, missing,
////                 CvDTreeParams(8, 10, 0, true, 15, 10, true, true, priors));
////    //存储多对象
////    //cvOpenFileStorage(<#const char *filename#>, <#CvMemStorage *memstorage#>, <#int flags#>)
////    //write(<#cv::FileStorage &fs#>, <#const string &name#>, <#int value#>)
////    
////    //save不能存储多对象
////    dtree->save("tree.xml", "MyTree");
////    dtree->clear();
////    //load函数存储了多对象，可以根据名称提取出对应的对象
////    dtree->load("tree.xml", "MyTree");
////    
////    //决策树的预测函数。sample是一个需要预测的浮点型的特征向量。missing_data_mask是一个同样长度和大小的字节向量，它的非零值预示着对应的特征丢失。raw_mode是用false指出输入类别没有归一化，反之用true，用于提高预测速度。
////    //CvDTreeNode* CvDTree::predict(const CvMat *sample, const CvMat* missing_data_mask = 0, bool raw_mode = 0);
////    CvDTreeNode* CvDTree::predict(<#const CvMat *sample#>)
////}
