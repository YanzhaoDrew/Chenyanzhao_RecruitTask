# ChenYanzhao_RecruitTask
test task
# 考核任务
//用于存放考核代码的位置
色块识别
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	Mat img,img_gray,dst;
	img = imread("D:\\Edge download\\Picture\\OpencvSave\\tag.png");
	if (img.empty()) {
		cout << "could not load image...\n";
		return -1;
	}
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	threshold(img_gray, dst, 125, 255, THRESH_BINARY);
	imshow("original", img);
	imshow("img_gary	output",img_gray);
	imshow("dst output", dst);

	waitKey(0);
	return 0;
}

# 进度汇报
已完成Ubuntu和Windows双系统配置  
     Ubuntu编译器vscode配置完成  
     Windows编译器vs2022上配置opencv完成  
|日期|学习过程|遇到问题|解决过程|
|--------|--------|--------|--------|
|10.10|学习到C++循环类型|预算符类型x++和++x的区别分不清|去CSDN查找解释，得到解决|
|10.12|学习到C++二维数组|过程中对于编写延时循环函数使用clock_t ks = clock();不是很懂|依旧CSDN找解释得知|
|10.14|进行C++题目练习熟悉|过程顺利|没有太大问题|
|10.15|最近学习opencv使用|过程使用hsv和灰度图像转换时报错|通过查找百度找得答案，已经是灰度图像不能转灰度，会报错|
|10.16|学习opencv色彩空间转换|对考核任务中图片绿色和蓝色色块进行转换，但是把其他一些相近颜色也转换了|查找选择的范围或者学习规定要识别的区域，还没解决|
|10.17|初步尝试色块识别|大概识别出色块，但是其他相近颜色也识别出来了||
