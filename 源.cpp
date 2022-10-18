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
	Mat edge;
	# 进行两次高斯模糊，去除噪点
	GaussianBlur(img, dst, Size(3, 3), 9, 9);
	GaussianBlur(dst, dst, Size(1, 1), 9, 9);
	# 进行色彩空间转换，转灰度以方便二阶导边缘化  
	cvtColor(dst, img_gray, COLOR_BGR2GRAY);
	# 进行拉普拉斯二阶导数计算  
	Laplacian(img_gray, edge, CV_16S, 3);
	# 进行取绝对值  
	convertScaleAbs(edge, edge);
	# 显示结果
	imshow("Ê¶±ð", edge);
	# 为使效果更佳，使用二值化，设置阈值  
	threshold(edge, edge, 0, 255, THRESH_OTSU | THRESH_BINARY);
	# 显示图像
	imshow("¶þÖµ»¯ºó", edge);
	waitKey(0);
	return 0;
}
