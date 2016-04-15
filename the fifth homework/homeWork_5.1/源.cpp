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
		cout << "�Ҳ���ͼ�����ͼ���Ѿ��� " << endl;
	else
	{
		imshow("ԭͼ", image);
		sharpen(image, result);
		waitKey();
	}
	return 0;
}

void sharpen(const Mat &image, Mat &result)
{
	result.create(image.size(), image.type());
	int nr = result.rows;
	int nl = result.cols*result.channels();//����ͨ����Ϊһͨ��
	for (int i = 1; i < nr - 1;i++)//���˵�һ���Լ����һ�У����������ж��ú˵�ê��ɨ��һ��
	{
		const uchar*prevoious = image.ptr<const uchar>(i - 1);//��һ��
		const uchar*current = image.ptr<const uchar>(i);//��ǰ��
		const uchar*next = image.ptr<const uchar>(i + 1);//��һ��
		uchar*output = result.ptr<uchar>(i);//�����
		for (int j = 1; j < nl - 1; j++)
		{
			*output++ = saturate_cast<uchar>( 0.125*current[j - 1] +0.125*current[j + 1] + 0.125*prevoious[j]+0.125*prevoious[j-1]+0.125*prevoious[j+1]+0.125*next[j]+0.125*next[j-1]+0.125*next[j+1]);
		}
	}
	//��δ�������������Ϊ0
	result.row(0).setTo(Scalar(0));
	result.row(nr- 1).setTo(Scalar(0));
	result.row(0).setTo(Scalar(0));
	result.col(result.cols- 1).setTo(Scalar(0));
	imshow("Ч��ͼ", result);
	imwrite("../image/result.bmp", result);
}
