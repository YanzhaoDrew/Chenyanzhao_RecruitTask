#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	# 定义需要识别的图像和转灰度化后的图像，以及高斯模糊后的图像  
	Mat img,img_gray,dst;
	# 读取存放好的图像  
	img = imread("D:\\Edge download\\Picture\\OpencvSave\\tag.png");
	#防止读取不到或者错误  
	if (img.empty()) {
		cout << "could not load image...\n";
		return -1;
	}
	# 定义边缘化后的图像  
	Mat edge1, edge2;
	# 进行两次高斯模糊，去除噪点
	GaussianBlur(img, dst, Size(3, 3), 9, 9);
	GaussianBlur(dst, dst, Size(1, 1), 9, 9);
	# 进行色彩空间转换，转灰度以方便二阶导边缘化  
	cvtColor(dst, img_gray, COLOR_BGR2GRAY);
	# 进行两次拉普拉斯二阶导数计算，使色块边缘更加明显
	Laplacian(img_gray, edge1, CV_16S, 1, 1, 0, BORDER_DEFAULT);
	Laplacian(edge1, edge2, CV_16S, 1, 1, 0, BORDER_DEFAULT);
	# 进行取绝对值  
	convertScaleAbs(edge2, edge2);
	# 显示结果
	imshow("Ê¶±ð", edge2);
	# 为使效果更佳，使用二值化，设置阈值  
	threshold(edge2, edge2, 0, 255, THRESH_OTSU | THRESH_BINARY);
	# 距离变换和归一化
	Mat distanceImg;
	distanceTransform(edge2, distanceImg, DIST_L1, 5, 5);
	normalize(distanceImg, distanceImg, 0, 1.2, NORM_MINMAX);
	threshold(distanceImg, distanceImg, 0.3, 1, THRESH_BINARY);
	#腐蚀化
	Mat kernel = getStructuringElement(MORPH_RECT, Size(13, 13), Point(-1, -1));
	Mat erodeImg;
	morphologyEx(distanceImg, erodeImg, MORPH_ERODE, kernel);
	# 显示图像
	imshow("¶þÖµ»¯ºó", distanceImg);
	waitKey(0);
	return 0;
}
