// 2.0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*2.1编写C++程序完成“圆形”以下功能：
（1）	定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法；
		（要求当用户不输入坐标数据时，能够默认为坐标原点（0，0））
（2）	定义一个圆形类，其属性包括圆心和半径；
（3）	创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果；
（4）	观察圆形对象以及Point类成员的构造函数与析构函数的调用。
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；
				 可以使用system("pause")进行程序的暂停；
			  2，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，
				 并观察和解释相关调用顺序及其原因）*/
#include "pch.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
class Point
{
public:
	float x = 0.0;
	float y = 0.0;
	Point();
	~Point();
	void initp()
	{
		cout << "please input the x and y: ";
		cin >> x >> y;
	}
	double distance(const Point b)
	{
		double dis;
		dis = pow(b.x - this->x, 2) + pow(b.y - this->y, 2);
		dis = sqrt(dis);
		return dis;
	}
};
Point::Point()
{
	cout << "Point has been created.\n";
}
Point::~Point()
{
	cout << "Point has been deleted.\n";
}
class Circle: public Point
{
public:
	double radius;
	Circle();
	~Circle();
	void initr()
	{
		cout << "please input the radius: ";
		cin >> radius;
	}
	void judge(const Circle b)
	{
		double dis;
		dis = this->distance(b);
		if ((dis <= b.radius + this->radius) && (dis >= abs(b.radius - this->radius)))
			cout << "1" << endl;
		else cout << "0" << endl;
	}
};
Circle::Circle()
{
	cout << "Circle has been created.\n";
}
Circle::~Circle()
{
	cout << "Circle has been deleted.\n";
}

int main()
{
	Circle C1, C2;
	C1.initr();
	C1.initp();
	C2.initr();
	C2.initp();
	C1.judge(C2);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


