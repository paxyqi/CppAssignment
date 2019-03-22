// 5.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*5.2 对Point类重载＋＋和――运算符
编写C++程序完成以下功能：
（1）	Point类的属性包括点的坐标（x，y）；
（2）	实现 Point类重载＋＋和――运算符：
	++p，--p，p++，p--；
	＋＋和――分别表示x，y增加或减少1。*/
#include <iostream>
using namespace std;
class Point {
public:
	Point(float X,float Y):x(X),y(Y){}
	~Point(){}
	Point operator++()
	{
		x = x + 1;
		y = y + 1;
		return Point(x, y);
	}
	Point operator++(int)
	{
		
		Point save(x, y);
		x = x + 1;
		y = y + 1;
		return save;
	}
	Point operator--()
	{
		x = x - 1;
		y = y - 1;
		return Point(x, y);
	}
	Point operator--(int)
	{

		Point save(x, y);
		x = x - 1;
		y = y - 1;
		return save;
	}
	void print()
	{
		cout << "x: " << x << " y: " << y << endl;
	}
private:
	float x;
	float y;
};


int main()
{
	float x, y;
	cout << "please input x and y: ";
	cin >> x >> y;
	Point p(x,y),a(0,0);
	cout << "the answer of p++ is: ";
	a=p++;
	a.print();
	cout << "the answer of ++p is: ";
	a=++p;
	a.print();
	cout << "the answer of p-- is: ";
	a=p--;
	a.print();
	cout << "the answer of --p is: ";
	a=--p;
	a.print();

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
