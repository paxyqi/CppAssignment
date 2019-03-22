// 5.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*5.1 虚函数
针对题目3的“形状”类，编写C++程序完成以下功能：
（1）	将【形状】 中的基类计算面积的方法定义为虚函数，比较与【形状（A）】程序的差异；
（2）	将【形状】中的基类定义为抽象类，比较与【形状（A）】程序的差异。
*/
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
	virtual void area()
	{
		cout << "call virtual function";
	}//3为抽象类，此处为虚函数,该虚函数未被调用

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
	rectangle(float l, float w) :length(l), width(w)
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
