//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
////#include"process.h"
////#include"variable.h"
//
//#define NUM 50     //读取image的个数
//
//int main(int argc, char *argv[])
//{
//    /*******************  设置相关参数 *******************/
//    CvCapture* pCapture = NULL;
//    pCapture = cvCreateCameraCapture(CV_CAP_ANY);
//
//    const char* WIN_SRC = "Source";
//    const char* WIN_RESULT = "Result";
//    
//    // 设置显示窗口
//    namedWindow(WIN_SRC, CV_WINDOW_AUTOSIZE );
//    namedWindow(WIN_RESULT, CV_WINDOW_AUTOSIZE);
//
//    IplImage *g_pGrayImage = NULL;
//    IplImage *g_pBinaryImage = NULL;
//    
//    int minX=320;//屏幕的一半
//    int maxX=240;
//    int minY=320;
//    int maxY=240;
//    
//    Mat frame;  // 输入视频帧序列
//    Mat frameHSV;   // hsv空间
//    Mat mask(frame.rows, frame.cols, CV_8UC1);  // 2值掩膜
//    Mat dst(frame); // 输出图像
//
//    bool lastImgHasHand=false;
//    
//    vector< vector<Point> > contours;   // 轮廓
//    vector< vector<Point> > filterContours; // 筛选后的轮廓
//    vector< Vec4i > hierarchy;    // 轮廓的结构信息
//    vector< Point > hull; // 凸包络的点集
//    
//    int previousX=0;
//    int previousY=0;
//    int count=0;
//    int presentX=0;
//    int presentY=0;
//    
//    // 存储测试图片的数组
////    const char *tmp_names[] = {
////        "/Users/Camlin_Z/Downloads/Gesture_Template/1.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/2.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/3.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/4.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/5.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/6.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/7.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/8.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/9.bmp",
////        "/Users/Camlin_Z/Downloads/Gesture_Template/10.bmp"
////    };
//
//    const char *tmp_names[] = {
//        "/Users/Camlin_Z/Downloads/Gesture/1.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/2.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/3.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/4.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/5.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/6.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/7.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/8.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/9.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/10.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/11.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/12.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/13.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/14.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/15.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/16.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/17.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/18.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/19.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/20.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/21.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/22.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/23.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/24.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/25.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/26.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/27.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/28.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/29.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/30.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/31.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/32.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/33.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/34.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/35.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/36.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/37.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/38.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/39.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/40.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/41.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/42.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/43.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/44.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/45.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/46.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/47.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/48.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/49.bmp",
//        "/Users/Camlin_Z/Downloads/Gesture/50.bmp",
//    };
//    
//    /**************************** 载入手势模板 **************************/
//    const int sample_num_perclass = 10;  //训练每类图片数量
//    const int class_num = 5;   //训练类数
//    const int image_cols = 20;  //自定义的存储测试图片数组的列数
//    const int image_rows = 20;  //自定义的存储测试图片数组的行数
//    
//    //每一行是每个训练样本对应的图像的所有像素点信息
//    float trainingData[class_num*sample_num_perclass][image_rows*image_cols] = {{0}};
//    //训练样本标签，每一行是每个训练样本对应的标签
//    float labels[class_num*sample_num_perclass][class_num]={{0}};
//
//    for (int i = 0; i < class_num-1; i++){
//        Mat srcImage = imread(tmp_names[i], CV_LOAD_IMAGE_GRAYSCALE);
//        Mat resizeImage;
//        Mat trainImage;
//        //if(!srcImage.empty()):判断接收到图片的矩阵是否为空
//        // 判断接收到图片的矩阵是否有数据
//        if (!srcImage.data){
//            printf("未找到文件: %s\n", tmp_names[i]);
//            continue;
//        }
//        //使用象素关系重采样。当图像缩小时候，该方法可以避免波纹出现
//        resize(srcImage,resizeImage,Size(image_cols,image_rows),(0,0),(0,0),CV_INTER_AREA);
//        // 设置阈值将图片进行二值化
//        threshold(resizeImage,trainImage,0,255,CV_THRESH_BINARY|CV_THRESH_OTSU);
//        //Canny(resizeImage ,trainImage ,150,100,3,false);
//        //cvCanny(&resizeImage,&trainImage,70,90,3);
//        
//        // 读取每类训练图像中的所有图像
//        for(int j = 0; j < sample_num_perclass-1; ++j)
//        {
//            // 读取每个训练图像中的所有像素点
//            for(int k = 0; k < image_rows * image_cols; ++k)
//            {
//                for(int p = 0; p < sample_num_perclass-1; ++p)
//                {
//                    trainingData[i*sample_num_perclass+p][k] = (float)trainImage.data[k];
//                    //trainingData[i*sample_mun_perclass+(j-1)][k] = (float)trainImage.at<unsigned char>((int)k/8,(int)k%8);//(float)train_image.data[k];
//                    //cout<<trainingData[i*sample_mun_perclass+(j-1)][k] <<" "<< (float)trainImage.at<unsigned char>(k/8,k%8)<<endl;
//                }
//            }
//        }
//    }
//    
//    // 设置训练数据矩阵
//    Mat trainingDataMat(class_num*sample_num_perclass, image_rows * image_cols, CV_32FC1, trainingData);
//    cout<<"trainingDataMat——OK！"<<endl;
//    
//    // 设置标签数据（将每一类的训练图像的对应类别标签设置为1，其他类别的标签设置为0）
//    for(int i = 0; i <= class_num-1; ++i)
//    {
//        for(int j = 0; j <= sample_num_perclass-1; ++j)
//        {
//            for(int k = 0; k < class_num; ++k)
//            {
//                if(k==i)
//                    labels[i*sample_num_perclass + j][k] = 1;
//                else labels[i*sample_num_perclass + j][k] = 0;
//            }
//        }
//    }
//    Mat labelsMat(class_num*sample_num_perclass, class_num, CV_32FC1,labels);
//    
//    //输出类别标签数组
//    cout<<"labelsMat:"<<endl;
//    cout<<labelsMat<<endl;
//    cout<<"labelsMat——OK！"<<endl;
//    
//    /**************************** 训练手势模板 **************************/
//    cout<<"training start...."<<endl;
//    CvANN_MLP bp;
//    // 设置BP神经网络的参数
//    CvANN_MLP_TrainParams params;
//    params.train_method = CvANN_MLP_TrainParams::BACKPROP;
//    params.bp_dw_scale = 0.001;
//    params.bp_moment_scale = 0.1;
//    params.term_crit = cvTermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS,10000,0.0001);  //设置结束条件
//    //params.train_method=CvANN_MLP_TrainParams::RPROP;
//    //params.rp_dw0 = 0.1;
//    //params.rp_dw_plus = 1.2;
//    //params.rp_dw_minus = 0.5;
//    //params.rp_dw_min = FLT_EPSILON;
//    //params.rp_dw_max = 50.;
//    
//    //Setup the BPNetwork
//    // layerSizes用于设置网络结构，如下就是设置了含有两个隐含层的网络结构，输入层的节点数为每一张测试图像的总像素点数，输出层为测试图像的类别数，隐含层节点数为像素点数的一半
//    //Mat layerSizes=(Mat_<int>(1,5) << image_rows*image_cols,128,128,128,class_mun);
//    Mat layerSizes=(Mat_<int>(1,4) << image_rows*image_cols,int(image_rows*image_cols/2),int(image_rows*image_cols/2),class_num);
//    bp.create(layerSizes,CvANN_MLP::SIGMOID_SYM,1.0,1.0);//CvANN_MLP::SIGMOID_SYM
//                                                 //CvANN_MLP::GAUSSIAN
//                                                 //CvANN_MLP::IDENTITY
//    cout<<"training...."<<endl;
//    bp.train(trainingDataMat, labelsMat, Mat(),Mat(), params);
//    
//    // 保存分类器分类数据
//    bp.save("/Users/Camlin_Z/Downloads/bpcharModel.xml");
//    
//    cout<<"training finish...bpModel1.xml saved "<<endl;
// 
//    
///*******************对摄像头获取到的图片进行形态学处理*******************/
//    cout<<"Show the image captured in the window and repeat ......"<<endl;
//    while(true)
//    {
//        frame = cvQueryFrame( pCapture );
//        if( frame.empty() )
//        {
//            cout << "摄像头打开失败！！！";
//            break;
//        }
//        // imshow用于显示矩阵类型的数据，不同于cvShowIamge
////        imshow( WIN_SRC, frame);
//
//        // 中值滤波，去除椒盐噪声（因为其明显优于邻域平均法）
//        medianBlur(frame, frame, 5);
//
//        // 将从摄像头获得到的RGB图像转换到HSV（也可以考虑将图像转换到YCbCr空间来进行处理）
//        cvtColor( frame, frameHSV, CV_BGR2HSV );
//
//        Mat dstTemp1(frame.rows, frame.cols, CV_8UC1);
//        Mat dstTemp2(frame.rows, frame.cols, CV_8UC1);
//
//        // 对HSV空间进行量化，得到2值图像，亮的部分为手的形状
//        //inRange(frameHSV, Scalar(2.56,51.2,38.4), Scalar(38.4,153.6,256), dstTemp1);
//        inRange(frameHSV, Scalar(0,30,30), Scalar(40,170,256), dstTemp1);   //原始程序
//        inRange(frameHSV, Scalar(156,30,30), Scalar(180,170,256), dstTemp2);
//
//        // bitwise_or：是将两张图像进行或操作（看一下HSV肤色模型）
//        bitwise_or(dstTemp1, dstTemp2, mask);
//        inRange(frameHSV, Scalar(0,30,30), Scalar(180,170,256), dst);
////        inRange(frameHSV, Scalar(2.56,51.2,38.4), Scalar(38.4,153.6,256), mask);  //直接将
//
//        // 形态学操作，去除噪声，并使手的边界更加清晰（可以分析是放在后面还是前面好）
//        Mat element = getStructuringElement(MORPH_RECT, Size(3,3));
//
//        // 对目标物体先腐蚀再膨胀形成一次开运算，一般用于去掉目标区域的突出物；先膨胀再腐蚀形成一次闭运算，一般用于消除鸿沟或小的孔洞
//        //（此处可以考虑进行两种运算对于实验结果的影响）
//
//        // 腐蚀操作
//        //erode(mask, mask, element);
//
//        morphologyEx(mask, mask, MORPH_OPEN, element);
//
//        // 膨胀操作
//        //dilate(mask, mask, element);
//
//        // 这一步执行了闭运算，相当于先执行了一次腐蚀操作，然后是开运算，接着膨胀操作，最后又执行了一次闭运算（考虑一下怎样排列这些操作可以实现最好的效果）
//        //morphologyEx(mask, mask, MORPH_CLOSE, element);
//        // 作用是把mask和dst重叠以后把mask中像素值为0（black）的点对应的dst中的点变为透明，而保留其他点。
//        frame.copyTo(dst, mask);
//        // 显示二值化图像
//        cvNamedWindow("test", CV_WINDOW_AUTOSIZE);
//        imshow("test", mask);
//        
//        /*********************  显示手势轮廓 ***********************/
//        contours.clear();
//        hierarchy.clear();
//        filterContours.clear();
//        // 得到手的轮廓
//        findContours(mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
//        
//        // 去除伪轮廓
//        for (size_t i = 0; i < contours.size(); i++)
//        {
//            //  approxPolyDP(Mat(contours[i]), Mat(approxContours[i]), arcLength(Mat(contours[i]), true)*0.02, true);
//            if (fabs(contourArea(Mat(contours[i]))) > 30000) //判断手进入区域的阈值
//            {
//                filterContours.push_back(contours[i]);
//            }
//        }
//        // 画轮廓
//        if(filterContours.size()>0)
//        {
//            count++;
//            lastImgHasHand=true;
//            drawContours(dst, filterContours, -1, Scalar(255,0,255), 3/*, 8, hierarchy*/);
//            
//            for (size_t j=0; j<filterContours.size(); j++)
//            {
//                convexHull(Mat(filterContours[j]), hull, true);
//                int hullcount = (int)hull.size();
//                for (int i=0; i<hullcount-1; i++)
//                {
//                    line(dst, hull[i+1], hull[i], Scalar(255,255,255), 2, CV_AA);//白色
//                    //printf("num%d:x=%d\ty=%d\t\n",i,hull[i].x,hull[i].y);
//                    if(hull[i].x>maxX)
//                        maxX=hull[i].x;
//                    if(hull[i].x<minX)
//                        minX=hull[i].x;
//                    if(hull[i].y>maxY)
//                        maxY=hull[i].y;
//                    if(hull[i].y<minY)
//                        minY=hull[i].y;
//                    //printf("miniX=%d\tminiY=%d\tmaxX=%d\tmaxY=%d\t\n",minX,minY,maxX,maxY);
//                    
//                }
//                
//                line(dst, hull[hullcount-1], hull[0], Scalar(0,255,0), 2, CV_AA);//绿色，最后一条
//                
//                if(count==1)//第一个轮廓的中心位置存在全局变量中，到最后一个再跟它比。
//                {
//                    previousX=(minX+maxX)/2;
//                    //printf("previousX=%d\n",previousX);
//                    previousY=(minY+maxY)/2;
//                    //printf("previousY=%d\n",previousY);
//                }
//                else
//                {
//                    presentX=(minX+maxY)/2;
//                    presentY=(minY+maxY)/2;
//                }
//            }
//        }
//        else
//        {
//            if(lastImgHasHand==true)
//            {
//                if((previousX-presentX)<0)//中文的大括号和英文的大括号用肉眼看不出来，坑啊
//                {
//                    //printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<left\n");//镜像，没有flip过来，所以这里注意点。
//                }
//                if((previousX-presentX)>0)
//                {
//                    //printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>right\n");
//                }
//                if((previousY-presentY)<0)
//                {
//                    //printf("downVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n");
//                }
//                if((previousY-presentY)>0)
//                {
//                    //printf("upAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa\n");
//                }
//                count=0;
//                lastImgHasHand=false;
//            }
//        }
//        //printf("previousX=%d\tpresentX=%d\tpreviousY=%d\tpresentY=%d\n",previousX,presentX,previousY,presentY);
//        //printf("count=%d\n",count);
//
//        // 显示手轮廓图像
//        imshow(WIN_RESULT, dst);
//        dst.release();
//        //cvReleaseImage(&pSrcImage);
//        cvReleaseImage(&g_pGrayImage);
//        cvReleaseImage(&g_pBinaryImage);
//
///**************************** 测试神经网络 **************************/
//        
//        cout << " testing start ... "<< endl;
//        Mat test_image = mask;
//        Mat test_temp;
//        //使用象素关系重采样。当图像缩小时候，该方法可以避免波纹出现
//        resize(test_image,test_temp,Size(image_cols,image_rows),(0,0),(0,0),CV_INTER_AREA);
//        threshold(test_temp,test_temp,0,255,CV_THRESH_BINARY|CV_THRESH_OTSU);
//        //cvCanny(&test_temp,&test_temp,70,90,3);
//        //Canny(test_temp ,test_temp ,150,100,3,false);
//    
//        // 将sampleMat初始化为一个 1 x image_rows*image_cols 的矩阵
//        Mat_<float>sampleMat(1,image_rows*image_cols);
//        for(int i = 0; i<image_rows*image_cols; ++i)
//        {
//            sampleMat.at<float>(0,i) = (float)test_temp.data[i];
//            //sampleMat.at<float>(0,i) = (float)test_temp.at<uchar>(i/8,i%8);
//        }
//        Mat responseMat;
//        
//        // 通过调用predict函数，得到一个1*nClass的输出向量，其中每一列说明它与该类的相似程度（0-1之间），即置信度。
//        bp.predict(sampleMat,responseMat);
//        Point maxLoc;
//        double maxVal = 0;
//        
//        // minMaxLoc寻找矩阵(一维数组当作向量,用Mat定义) 中最小值和最大值的位置.
//        minMaxLoc(responseMat,NULL,&maxVal,NULL,&maxLoc);
//        cout<<"识别结果："<<maxLoc.x<<"  相似度:"<<maxVal*100<<"%"<<endl;
////        imshow("test_image",test_image);
//       
//        char c;
//        c = cvWaitKey(1);
//        if (c == 27)
//            break;
//    }
//    
////    /**************************** 测试神经网络 **************************/
////    cout << " testing start ... " << endl;
////    Mat test_image = imread("/Users/Camlin_Z/Downloads/Gesture/50.bmp",CV_LOAD_IMAGE_GRAYSCALE);
////    Mat test_temp;
////    //使用象素关系重采样。当图像缩小时候，该方法可以避免波纹出现
////    resize(test_image,test_temp,Size(image_cols,image_rows),(0,0),(0,0),CV_INTER_AREA);
////    threshold(test_temp,test_temp,0,255,CV_THRESH_BINARY|CV_THRESH_OTSU);
////    //cvCanny(&test_temp,&test_temp,70,90,3);
////    //Canny(test_temp ,test_temp ,150,100,3,false);
////    
////    // 将sampleMat初始化为一个 1 x image_rows*image_cols 的矩阵
////    Mat_<float>sampleMat(1,image_rows*image_cols);
////    for(int i = 0; i < image_rows*image_cols; ++i)
////    {
////        sampleMat.at<float>(0,i) = (float)test_temp.data[i];
////        //sampleMat.at<float>(0,i) = (float)test_temp.at<uchar>(i/8,i%8);
////    }
////    Mat responseMat;
////    
////    //通过调用predict函数，得到一个1*nClass的输出向量，其中每一列说明它与该类的相似程度（0-1之间），即置信度。
////    bp.predict(sampleMat,responseMat);
////    Point maxLoc;
////    double maxVal = 0;
////    //  minMaxLoc寻找矩阵(一维数组当作向量,用Mat定义) 中最小值和最大值的位置.
////    minMaxLoc(responseMat, NULL, &maxVal, NULL, &maxLoc);
////    cout<<"识别结果："<<maxLoc.x+1<<"  相似度:"<<maxVal*100<<"%"<<endl;
//////    imshow("test_image",test_image);
//
//    return 0;
//}
