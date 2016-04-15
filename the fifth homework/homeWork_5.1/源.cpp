#include<iostream>
#include"opencv.hpp"

using namespace std;
using namespace cv;
void sharpen(const Mat &image, Mat &result);
int main()
{
	Mat image = imread("../image/test.jpg");
	Mat result;

	if (!image.data)
		cout << "找不到图像或者图像已经损坏 " << endl;
	else
	{
		imshow("原图", image);
		sharpen(image, result);
		waitKey();
	}
	return 0;
}

void sharpen(const Mat &image, Mat &result)
{
	result.create(image.size(), image.type());
	int nr = result.rows;
	int nl = result.cols*result.channels();//把三通道变为一通道
	for (int i = 1; i < nr - 1;i++)//除了第一行以及最后一行，其余所有行都用核的锚点扫描一遍
	{
		const uchar*prevoious = image.ptr<const uchar>(i - 1);//上一行
		const uchar*current = image.ptr<const uchar>(i);//当前行
		const uchar*next = image.ptr<const uchar>(i + 1);//下一行
		uchar*output = result.ptr<uchar>(i);//输出行
		for (int j = 1; j < nl - 1; j++)
		{
			*output++ = saturate_cast<uchar>( 0.125*current[j - 1] +0.125*current[j + 1] + 0.125*prevoious[j]+0.125*prevoious[j-1]+0.125*prevoious[j+1]+0.125*next[j]+0.125*next[j-1]+0.125*next[j+1]);
		}
	}
	//将未处理的像素设置为0
	result.row(0).setTo(Scalar(0));
	result.row(nr- 1).setTo(Scalar(0));
	result.row(0).setTo(Scalar(0));
	result.col(result.cols- 1).setTo(Scalar(0));
	imshow("效果图", result);
	imwrite("../image/result.bmp", result);
}
