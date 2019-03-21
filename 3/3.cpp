// 3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*3、继承与派生实验
编写C++程序完成“形状”的以下功能：
（1）	声明一个基类Shape（形状），其中包含一个方法来计算面积；
（2）	从Shape派生两个类：矩形类和圆形类；
（3）	从矩形类派生正方形类；
（4）	分别实现派生类构造函数、析构函数和其他方法；
（5）	创建派生类的对象，观察构造函数、析构函数调用次序；
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；可以使用system("pause")进行程序的暂停；2，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因）
（6）	对不同对象计算面积。*/

#include <iostream>
using namespace std;
const float PI = 3.1415;
class Shape
{
public:
	Shape()
	{
		cout << "call shape" << endl;
	}
	~Shape()
	{
		cout << "call shape over" << endl;
	}
	virtual void area() = 0;

protected:

};
class circle :public Shape {
public:
	circle(float r) :radius(r)
	{
		cout << "call circle" << endl;
	}
	~circle()
	{
		cout << "call circle over" << endl;
	}
	void area()
	{
		cout << PI * radius * radius << endl;
	}
protected:
	float radius;

};
class rectangle :public Shape {
public:
	rectangle()
	{
		cout << "call rectangle" << endl;
	}
	rectangle(float l,float w):length(l),width(w)
	{
		cout << "call rectangle" << endl;
	}
	~rectangle()
	{
		cout << "call rectangle over" << endl;
	}
	void area()
	{
		cout << length * width << endl;
	}
protected:
	float length;
	float width;
};
class square :public rectangle {
public:
	square(float e) :edge(e)
	{
		cout << "call square" << endl;
	}
	~square()
	{
		cout << "call square over" << endl;
	}
	void area()
	{
		cout << edge * edge << endl;
	}
private:
	float edge;
};


int main()
{
	float radius, edge, length, width;
	cout << "please input the radius,length, width, edge" << endl;
	cin >> radius >> length >> width >> edge;
	circle C(radius);
	rectangle R(length, width);
	square S(edge);
	C.area();
	S.area();
	R.area();
	return 0;
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
