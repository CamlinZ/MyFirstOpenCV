////
////  processfuction.cpp
////  MyFirstOpenCV
////
////  Created by 张才明 on 2017/5/6.
////  Copyright © 2017年 CCNU. All rights reserved.
////
//
//#include <stdio.h>
//#include"process.h"
//#include "variable.h"
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////初始化YcrCb
//void init_hand_YCrCb()
//{
//    //
//    img_YCrCb = cvCreateImage(sz, 8, 3);
//    YCrCb_mask = cvCreateImage(sz, IPL_DEPTH_8U, 1);;
//    
//    //最终的图片
//    YCrCb = cvCreateImage(sz, IPL_DEPTH_8U, 3);
//    
//    
//    //三通道
//    Y_channel = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    Cr_channel = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    Cb_channel = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    
//    //按范围截取后
//    Y_cmp = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    Cr_cmp = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    Cb_cmp = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    
//    //Y,Cr,Cb的颜色范围
//    Y_lower = CV_RGB(0, 0, 130);
//    Y_upper = CV_RGB(0, 0, 130);
//    
//    Cr_lower = CV_RGB(0, 0, 125);
//    Cr_upper = CV_RGB(0, 0, 125);
//    
//    Cb_lower = CV_RGB(0, 0, 132);
//    Cb_upper = CV_RGB(0, 0, 147);
//    
//    YCrCb_lower = cvScalar(0, 0, 132, 0);
//    YCrCb_upper = cvScalar(130, 125, 147, 0);
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void hand_YCrCb()
//{
//    //转换到YCrBr
//    cvCvtColor(src3, img_YCrCb, CV_RGB2YCrCb);
//    
//    
//    //分割到Y,Cr,Cb
//    cvSplit(img_YCrCb, Y_channel, Cr_channel, Cb_channel, 0);
//    
//    //将Y_channel的位于 Y_lower 和 Y_upper 之间的元素复制到 Y_tmp中
//    cvInRangeS(Y_channel, Y_lower, Y_upper, Y_cmp);
//    cvInRangeS(Cr_channel, Cr_lower, Cr_upper, Cr_cmp);
//    cvInRangeS(Cb_channel, Cb_lower, Cb_upper, Cb_cmp);
//    
//    //合并Y,Cr,Cb通道到YCrCb中
//    cvMerge(Y_cmp, Cr_cmp, Cb_cmp, 0, YCrCb);
//    
//    //显示结果
//    cvShowImage("YCrCb_mask", YCrCb);
//    
//    
//    //cvInRangeS (img_YCrCb, YCrCb_lower, YCrCb_upper, YCrCb_mask);
//    //cvShowImage( "YCrCb_mask", YCrCb_mask);
//    
//    
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//void color_blance()
//{
//    CvScalar avg = cvAvg(H_img, 0);
//    printf("%f, %f, %f, %f\n", avg.val[0], avg.val[1], avg.val[2], avg.val[3]);
//    double d = 128 - avg.val[0];
//    avg.val[0] = d;
//    cvAddS(H_img, avg, H_img, 0);
//}
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//void init_hand_HSV()
//{
//    
//    hsv_image = cvCreateImage(sz, 8, 3);
//    hsv_mask = cvCreateImage(sz, 8, 1);
//    hsv_min = cvScalar(0, 20, 20, 0);
//    hsv_max = cvScalar(20, 250, 255, 0);
//    //hsv_mask->origin = 1;
//    
//    //方法2: 单独处理各个通道
//    H_img = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    S_img = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    V_img = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    
//    H_mask = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    H_mask1 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    S_mask = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    S_mask1 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    V_mask = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    V_mask2 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    V_mask1 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void hand_HSV()
//{
//    cvCvtColor(src3, hsv_image, CV_BGR2HSV);
//    //cvInRangeS (hsv_image, hsv_min, hsv_max, hsv_mask);
//    //cvShowImage( "hsv_msk", hsv_mask);
//    
//    //方法2: 单独处理各个通道
//    cvSplit(hsv_image, H_img, S_img, V_img, 0);
//    
//    //color_blance();
//    //cvMerge(H_img,S_img,V_img,0,hsv_image);
//    //cvShowImage( "色彩平衡后", hsv_image);
//    //cvShowImage( "H通道", H_img);
//    
//    //直方图均衡化(效果更差)
//    //cvEqualizeHist(H_img, H_img);
//    
//    //cvShowImage( "H通道_均衡化", H_img);
//    
//    //自适应
//    //cvAdaptiveThreshold(H_img, H_mask, 30, 0, 0, 3, 5);
//    
//    //cvShowImage( "H", H_img);
//    //cvShowImage( "S", S_img);
//    //cvShowImage( "V", V_img);
//    
//    
//    //色相
//    cvInRangeS(H_img, cvScalar(0, 0, 0, 0), cvScalar(H_low_max, 0, 0, 0), H_mask);//红色区
//    cvInRangeS(H_img, cvScalar(256 - H_high_min, 0, 0, 0), cvScalar(256, 0, 0, 0), H_mask1);//紫色区
//    
//    //饱和度
//    
//    cvInRangeS(S_img, cvScalar(S_low, 0, 0, 0), cvScalar(S_high, 0, 0, 0), S_mask); //中间区
//    //cvInRangeS(S_img,cvScalar(20,0,0,0),cvScalar(100,0,0,0),S_mask1); //低饱和度
//    
//    
//    
//    //亮度
//    cvInRangeS(V_img, cvScalar(V_high, 0, 0, 0), cvScalar(256, 0, 0, 0), V_mask);//高亮区
//    cvInRangeS(V_img, cvScalar(V_low, 0, 0, 0), cvScalar(V_high, 0, 0, 0), V_mask1); //中间区
//    //cvInRangeS(V_img,cvScalar(150,0,0,0),cvScalar(250,0,0,0),V_mask2); //较亮区
//    
//    
//    //红黄, 和蓝紫的混合
//    cvOr(H_mask1, H_mask, H_mask, 0);
//    
//    //消除饱和度过低区域
//    cvAnd(H_mask, S_mask, H_mask, 0);
//    
//    //cvShowImage( "饱和度过滤", H_mask);
//    
//    //消去过亮过暗区域
//    cvAnd(H_mask, V_mask1, H_mask, 0);
//    
//    //cvShowImage( "亮度过滤", H_mask);
//    //cvShowImage( "hsv_msk", H_mask);
//    
//    //补偿过亮区域
//    if (if_high_light) cvOr(H_mask, V_mask, H_mask, 0);
//    
//    //cvShowImage( "补偿高光", H_mask);
//    
//    //cvShowImage( "曝光过度 V", V_mask);
//    //cvShowImage( "曝光补偿", S_mask);
//    
//    
//    //是否补偿曝光过度
//    hsv_mask = H_mask;
//    
//    cvShowImage( "hsv_msk", H_mask);
//    
//}
//
//void inti_threshold()
//{
//    thd_src = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    thd_dst1 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//    thd_dst2 = cvCreateImage(sz, IPL_DEPTH_8U, 1);
//}
//
//void threshold()
//{
//    //cvCvtColor(hsv_mask, thd_src, CV_RGB2GRAY);//src1被修改为src3
//    thd_src = hsv_mask;
//    cvAdaptiveThreshold(thd_src, thd_dst1, thd_max, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 3, 5);
//    //cvThreshold(thd_src, thd_dst2, thd_val, thd_max, CV_THRESH_BINARY);
//    
//    cvShowImage("阀值前", thd_src);
//    
//    cvShowImage("阀值化1", thd_dst1);
//    cvCreateTrackbar("thd_max", "阀值化1", &thd_max, 256, 0);
//    cvShowImage("阀值化2", thd_dst2);
//    cvCreateTrackbar("thd_val", "阀值化2", &thd_val, 256, 0);
//}
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void resizeSrc()
//{
//    double scale = 0.5;
//    
//    
//    //获得图像大小
//    sz = cvGetSize(src);
//    newSize.height = (int)(sz.height * scale);
//    newSize.width = (int)(sz.width * scale);
//    
//    src = cvCreateImage(newSize, IPL_DEPTH_8U, 3);
//    
//    cvResize(src, src, CV_INTER_LINEAR);
//    
//}
//
//
//void reduce_noise()
//{
//    //cvSmooth(hsv_mask, smooth1, CV_GAUSSIAN, 3, 0, 0, 0);
//    //cvSmooth(hsv_mask, smooth1, CV_MEDIAN, 3, 0, 0, 0);
//    
//    //cvSmooth(smooth1, smooth1, CV_BILATERAL, 3, 0, 0, 0);
//    
//    //cvDilate(hsv_mask, smooth1, 0 ,2);
//    //cvErode(smooth1 ,smooth2, 0, 2);
//    
//    //cvCvtColor(src3, hsv_mask, CV_RGB2GRAY);
//    //cvShowImage("扩张腐蚀", smooth1);
//    cvMorphologyEx(hsv_mask,smooth1, 0, NULL, CV_MOP_CLOSE, MopEx_value);
//    //cvMorphologyEx(smooth1, smooth2, 0, CV_SHAPE_RECT, CV_MOP_OPEN, 1);
//    
//    cvShowImage("扩张腐蚀", smooth1);
//    
//    //cvSmooth(smooth2, smooth3, CV_MEDIAN, 9, 0, 0, 0);
//    
//    //cvShowImage( "平滑", smooth3);
//}
//
//
/////////////////////////////////////////////////////////////////////////////
//
//void hand_contours(IplImage* dst) {
//    
//    if (g_storage == NULL) {
//        g_storage = cvCreateMemStorage(0);
//        g_storage1 = cvCreateMemStorage(0);
//        g_storage2 = cvCreateMemStorage(0);
//    }
//    else {
//        cvClearMemStorage(g_storage);
//        cvClearMemStorage(g_storage1);
//        cvClearMemStorage(g_storage2);
//    }
//    
//    
//    int i = 0, j = 0;
//    CvSeq* contours = 0;
//    CvSeq* contoursHead = 0;
//    CvSeq* p = NULL;
//    CvSeq* q = NULL;
//    
//    seqMidObj = 0;
//    handNum = 0;
//    
//    //cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
//    
//    cvFindContours(dst, g_storage, &contours, sizeof(CvContour), CV_RETR_EXTERNAL);//只查找外轮廓
//    contoursHead = contours;//contours的头
//    //cvZero( g_gray );
//    
//    /*CvSeq* seqApprox;
//     
//     CvSeq* head;
//     int j=0;*/
//    /*for(p=contours;p != NULL; p = p->h_next){
//     
//     j++;
//     
//     seqApprox = cvApproxPoly(p, sizeof(CvContour),g_storage1, CV_POLY_APPROX_DP, 2, 0);
//     seqApprox = seqApprox->h_next;
//     if(p==contours) head  = seqApprox;
//     
//     }
//     printf("total = %d\n ",j );
//     seqApprox = head;*/
//    
//    
//    cvZero(tmp3);
//    //cvZero( tmp2 );
//    
//    if (contours)cvDrawContours(tmp3, contours, cvScalarAll(255), cvScalar(255, 0, 0, 0), 1);//绘制轮廓
//    //if( contours )cvDrawContours( tmp2, seqApprox, cvScalar(255,0,0,0),cvScalar(255,100,0,0),1);//绘制轮廓
//    
//    cvShowImage( "查找轮廓", tmp3);
//    
//    //CvSeq* seqMidObj = 0;// = cvCreateSeq(CV_SEQ_ELTYPE_CODE, sizeof(CvSeq), sizeof(int),g_storage2);
//    
//    
//    //去除与窗口邻接的轮廓
//    contours = contoursHead; i = 0;
//    CvRect bound;
//    int dat = 2;
//    
//    //去除小面积区域
//    int contArea = 0;
//    int imgArea = newSize.height * newSize.width;
//    
//    for (; contours != 0; contours = contours->h_next){
//        
//        i++;
//        
//        //如果面积过小, 则排除
//        contArea = fabs(cvContourArea(contours, CV_WHOLE_SEQ));
//        
//        if ((double)contArea / imgArea < 0.015){ continue; }
//        
//        //如果边界与窗口相连, 则排除
//        bound = cvBoundingRect(contours, 0);
//        
//        if (bound.x < dat
//            || bound.y < dat
//            || bound.x + bound.width + dat > newSize.width
//            || bound.y + bound.height + dat > newSize.height)
//        {
//            //printf(" %d, %d, %d, %d\n",bound.x, bound.y, bound.width, bound.height );
//            //cvRectangle(tmp3, cvPoint(bound.x, bound.y),cvPoint(bound.x + bound.width, bound.y + bound.height),cvScalar(255,255,255,255),1,8,0);
//            continue;
//        }
//        
//        //建立轮廓链表
//        q = p;
//        //p = cvCloneSeq(contours, g_storage2);
//        p = contours;
//        
//        if (q == NULL){
//            seqMidObj = p;
//            //p->h_next = NULL;
//            //p->h_prev = NULL;
//            //printf("第1个!");
//        }
//        else{
//            q->h_next = p;
//            p->h_prev = q;
//            //printf("1个!");
//        }
//        //j++;
//        handNum++;
//        
//    }
//    
//    //printf("找到轮廓: %d 个   塞选: %d 个\n", i,j);
//    
//    if (seqMidObj){
//        seqMidObj->h_prev = NULL;
//        p->h_next = NULL;
//    }
//    if (handNum>0) printf("找到手: %d  ", handNum);
//    //CvSeq* seqMidObj_head = seqMidObj;
//    
//    cvZero(tmp3);
//    if (seqMidObj)cvDrawContours(tmp3, seqMidObj, cvScalarAll(255), cvScalar(255, 0, 0, 0), 1);//绘制轮廓
//    cvShowImage("轮廓塞选", tmp3);
//}
//
//
//
///////////////////////////////////////////////////////
//
////载入模板的轮廓
//void init_hand_template()
//{
//    storage_tmp = cvCreateMemStorage(0);
//    int i = 0;
//    for (i = 0; i<handTNum; i++){
//        
//        tmp_img = cvLoadImage(tmp_names[i], CV_LOAD_IMAGE_GRAYSCALE);
//        if (!tmp_img){
//            printf("未找到文件: %s\n", tmp_names[i]);
//            continue;
//        }
//        //cvShowImage("载入模板", tmp_img);
//        handT1 = handT2;
//        
//        //int cvFindContours(CvArr* image, CvMemStorage* storage, CvSeq** first_contour,int header_size=sizeof(CvContour),
//        //int mode=CV_RETR_LIST, int method=CV_CHAIN_APPROX_SIMPLE, CvPoint offset=cvPoint(0,0));
//        //image:输入的 8-比特、单通道图像. 非零元素被当成 1，0 象素值保留为 0 - 从而图像被看成二值的。为了从灰度图像中得到这样的二值图像，
//        //可以使用 cvThreshold, cvAdaptiveThreshold 或 cvCanny. 本函数改变输入图像内容。storage：得到的轮廓的存储容器
//        //first_contour：输出参数：包含第一个输出轮廓的指针;header_size：如果 method=CV_CHAIN_CODE，则序列头的大小 >=sizeof(CvChain)，
//        //否则 >=sizeof(CvContour); mode：提取模式. CV_RETR_EXTERNAL - 只提取最外层的轮廓
//        cvFindContours(tmp_img, storage_tmp, &handT2, sizeof(CvContour), CV_RETR_EXTERNAL);
//        if (handT2){
//            printf("载入模板: %s 成功!\n", tmp_names[i]);
//            if (handT1 == NULL){
//                printf("载入第一个模板!\n");
//                handT = handT2;
//            }
//            else{
//                handT2->h_prev = handT1;
//                handT1->h_next = handT2;
//            }
//        }
//    }
//}
//
//
////模板匹配手
//void hand_template_match(CvSeq* handT, CvSeq* hand){
//    int i = 0;
//    int kind = -1;
//    double hu = 1;
//    
//    double hutmp;
//    CvSeq* handp = handT;
//    int method = CV_CONTOURS_MATCH_I1;
//    
//    match_num = 0;
//    
//    if (handT == NULL){ return; printf("handT==NULL!\n"); }
//    if (hand == NULL){ return; printf("hand==NULL!\n"); }
//    
//    for (i = 0; i<handTNum; i++){
//        hutmp = cvMatchShapes(handp, hand, method, 0);
//        handp = handp->h_next;
//        
//        //找到hu矩最小的模板
//        if (hu > hutmp){
//            hu = hutmp;
//            kind = i + 1;
//        }
//        
//        //printf("%f ", hu);
//    }
//    
//    //显示匹配结果
//    if (hu<((double)Hmatch_value) / 100){
//        printf("匹配模板: %d (%f)", kind, hu);
//        match_num = kind;
//        if_match_num = true;
//    }
//    else{
//        if_match_num = false;
//    }
//}
//
//
//
//void init_laplace()
//{
//    int i;
//    for (i = 0; i < 3; i++)
//        planes[i] = cvCreateImage(newSize, 8, 1);
//    laplace = cvCreateImage(newSize, IPL_DEPTH_16S, 1);
//    colorlaplace = cvCreateImage(newSize, 8, 3);
//    
//}
//
//
//void toLaplace(IplImage* dst)
//{
//    int i, c, ksize;
//    
//    ksize = (sigma * 5) | 1;
//    //cvSmooth( dst, colorlaplace, smoothType, ksize, ksize, sigma, sigma );
//    
//    cvSplit(dst, planes[0], planes[1], planes[2], 0);
//    for (i = 0; i < 3; i++)
//    {
//        cvLaplace(planes[i], laplace, 5);
//        cvConvertScaleAbs(laplace, planes[i], (sigma + 1)*0.25, 0);
//    }
//    cvMerge(planes[0], planes[1], planes[2], 0, colorlaplace);
//    colorlaplace->origin = dst->origin;
//    
//    //前期平滑
//    //cvMorphologyEx(planes[2], planes[2], 0, CV_SHAPE_RECT, CV_MOP_CLOSE, 1);
//    
//    cvShowImage("拉普拉斯变换", colorlaplace);
//    
//    //smoothType = smoothType == CV_GAUSSIAN ? CV_BLUR : smoothType == CV_BLUR ? CV_MEDIAN : CV_GAUSSIAN;
//    
//    cvCvtColor(colorlaplace, colorlaplace, CV_BGR2HSV);
//    
//    cvSplit(colorlaplace, planes[0], planes[1], planes[2], 0);
//    //检测图像像素灰度是否属于某一指定的范围
//    cvInRangeS(planes[2], cvScalar(ls_low, 0, 0, 0), cvScalar(256, 0, 0, 0), planes[2]);
//    
//    //后期平滑
//    //cvMorphologyEx(planes[2], planes[2], 0, CV_SHAPE_RECT, CV_MOP_CLOSE, 1);
//    //cvSmooth(planes[2], planes[2], CV_MEDIAN, 3, 0, 0, 0);
//    //cvErode(planes[2] ,planes[2], 0, 1);
//    
//    cvShowImage("拉普拉斯_边缘化", planes[2]);
//}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////求手的中点和移动方向
//void hand_direction(CvSeq* hand){
//    
//    //如果没有手, 则清除结果
//    if (!hand){
//        hand_center = cvPoint(0, 0);
//        hand_center_last = cvPoint(0, 0);
//        hand_direct_now = cvPoint(0, 0);
//        hand_direct_last = cvPoint(0, 0);
//        hand_direct = cvPoint(0, 0);
//        return;
//    }
//    
//    hand_center_last = hand_center;
//    
//    //获得中心点
//    CvRect bound = cvBoundingRect(hand, 0);
//    hand_center.x = bound.x + bound.width / 2;
//    hand_center.y = bound.y + bound.height / 2;
//    
//    if (hand_center_last.x != 0){
//        hand_direct_now.x = hand_center.x - hand_center_last.x;
//        hand_direct_now.y = hand_center.y - hand_center_last.y;
//        
//        if (hand_direct_now.x != 0){
//            
//            hand_direct.x = (hand_direct_now.x + hand_direct_last.x) / 2;
//            if (hand_direct.x != 0){
//                printf("  X 移动: %d ", hand_direct.x);
//            }
//            
//        }
//        if (hand_direct_now.y != 0){
//            
//            hand_direct.y = (hand_direct_now.y + hand_direct_last.y) / 2;
//            if (hand_direct.y != 0){
//                printf("  Y 移动: %d ", hand_direct.y);
//            }
//        }
//        
//    }
//}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////绘制识别结果
//void hand_draw(IplImage* dst, CvSeq* hands)
//{
//    
//    if (!hands) return;
//    
//    CvRect bound;
//    
//    //凸包
//    int i, hullcount;
//    CvPoint pt0;
//    CvSeq* hull;
//    
//    CvSeq* handp = hands;
//    
//    //凸包缺陷
//    CvConvexityDefect* defect;
//    CvSeq* hullDefect;
//    //CvSeq* hullDefectSelect;
//    int hullDefectNum = 0;
//    //cvPoint** points = (cvPoint*)malloc(sizeof(cvPoint)*3);
//    //cvPoint points[3];
//    
//    //绘制轮廓
//    cvDrawContours(dst, handp, cvScalar(255, 150, 100, 0), cvScalar(255, 0, 0, 0), 1, 1, 8, cvPoint(0, 0));
//    
//    CvFont font;
//    
//    
//    //绘制检测到的数字
//    if (if_match_num){
//        
//        //外阴影
//        cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 1.0f, 1.0f, 0, 5, 8);
//        cvPutText(dst, num_c[match_num - 1], cvPoint(5, 30), &font, CV_RGB(255, 255, 255));
//        //内颜色
//        cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 1.0f, 1.0f, 0, 2, 8);
//        cvPutText(dst, num_c[match_num - 1], cvPoint(5, 30), &font, CV_RGB(255, 0, 0));
//    }
//    //绘制移动方向
//    if (1){
//        
//        //cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,1.0f,1.0f,0,2,8);
//        //cvPutText(dst, "X: ", cvPoint(5, 30), &font, CV_RGB(255,0,0));
//    }
//    
//    
//    //对提取出的轮廓遍历
//    for (; handp != 0; handp = handp->h_next){
//        bound = cvBoundingRect(handp, 0);
//        //求并绘制中心点
//        //内颜色
//        int det = 2;
//        cvRectangle(dst,
//                    cvPoint(hand_center.x - det, hand_center.y - det),
//                    cvPoint(hand_center.x + det, hand_center.y + det),
//                    CV_RGB(0, 0, 0), 3, 8, 0);
//        
//        //外轮廓
//        det = 3;
//        cvRectangle(dst,
//                    cvPoint(hand_center.x - det, hand_center.y - det),
//                    cvPoint(hand_center.x + det, hand_center.y + det),
//                    CV_RGB(255, 255, 255), 1, 8, 0);
//        
//        
//        
//        //绘出外包络方框
//        cvRectangle(dst,
//                    cvPoint(bound.x, bound.y),
//                    cvPoint(bound.x + bound.width, bound.y + bound.height),
//                    cvScalar(0, 0, 255, 0), 2, 8, 0);
//        
//        //寻找凸包
//        hull = cvConvexHull2(handp, 0, CV_CLOCKWISE, 0);
//        hullcount = hull->total;
//        //printf("凸包点数: %d  ",hullcount);
//        
//        pt0 = **CV_GET_SEQ_ELEM(CvPoint*, hull, hullcount - 1);
//        
//        //画凸包
//        for (i = 0; i < hullcount; i++){
//            
//            //得到凸包的点
//            CvPoint pt = **CV_GET_SEQ_ELEM(CvPoint*, hull, i);
//            cvLine(dst, pt0, pt, CV_RGB(0, 255, 0), 1, CV_AA, 0);
//            pt0 = pt;
//        }
//        
//        //检查缺陷
//        /*if(!cvCheckContourConvexity(hands)){
//         
//         hullDefect = cvConvexityDefects(hands, hull, 0);
//         hullDefectNum = hullDefect->total;
//         printf("缺陷个数: %d  ",hullDefectNum);
//         for( i = 0; i < hullDefectNum; i++ ){
//         
//         defect = (CvConvexityDefect*)cvGetSeqElem(hullDefect, i);
//         
//         cvLine( dst, cvPoint(defect->end->x,defect->end->y),    cvPoint(defect->depth_point->x,defect->depth_point->y), CV_RGB(150,150,150),1,8,0);
//         cvLine( dst, cvPoint(defect->start->x,defect->start->y),cvPoint(defect->depth_point->x,defect->depth_point->y), CV_RGB(150,150,150),1,8,0);
//         
//         
//         }
//         
//         }*/
//        
//    }
//    
//}
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//void resizeAllWindow()
//{
//    cvNamedWindow("src", 0);
//    
//    cvNamedWindow("扩张腐蚀", 0);
//    
//    cvNamedWindow("最终识别", 0);
//    cvResizeWindow("src", newSize.width, newSize.height);
//    
//    cvNamedWindow("参数调试", 0);
//    cvResizeWindow("参数调试", newSize.width*1.5, 60 * 11);
//    
//    
//    cvCreateTrackbar("均值漂移滤波", "参数调试", &pmsf_value, 20, 0);
//    cvCreateTrackbar("开运算降噪", "参数调试", &MopEx_value, 5, 0);
//    
//    cvCreateTrackbar("色相红黄区", "参数调试", &H_low_max, 150, 0);
//    cvCreateTrackbar("色相蓝紫区", "参数调试", &H_high_min, 150, 0);
//    
//    cvCreateTrackbar("亮度下限", "参数调试", &V_low, 100, 0);
//    cvCreateTrackbar("亮度上限", "参数调试", &V_high, 256, 0);
//    
//    cvCreateTrackbar("饱和度下限", "参数调试", &S_low, 100, 0);
//    cvCreateTrackbar("饱和度上限", "参数调试", &S_high, 255, 0);
//    
//    cvCreateTrackbar("高光补偿", "参数调试", &if_high_light, 1, 0);
//    
//    cvCreateTrackbar("match系数", "参数调试", &Hmatch_value, 50, 0);
//    
//    
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
////这段代码转移到 handDlg.cpp
////
//////控制鼠标
////void control_mouse()
////{
////	CPoint point;
////	GetCursorPos(&point);
////
////	int scale = 10;
////	
////	point.x += hand_direct.x * scale;
////	point.y += hand_direct.y * scale;
////		
////	SetCursorPos( point.x, point.y);
////
////
////}
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////图像锐化处理
//void sharpenImage1(const cv::Mat &image, cv::Mat &result)
//{
//    //创建并初始化滤波模板
//    cv::Mat kernel(3, 3, CV_32F, cv::Scalar(0));
//    kernel.at<float>(1, 1) = 5.0;
//    kernel.at<float>(0, 1) = -1.0;
//    kernel.at<float>(1, 0) = -1.0;
//    kernel.at<float>(1, 2) = -1.0;
//    kernel.at<float>(2, 1) = -1.0;
//    
//    result.create(image.size(), image.type());
//    
//    //对图像进行滤波
//    cv::filter2D(image, result, image.depth(), kernel);
//}
