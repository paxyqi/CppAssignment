// 4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*4、I / O流实验
编写C++程序完成猜价格游戏的以下功能：
（1）	假定有一件商品，程序用随机数指定该商品的价格（1 - 1000的整数）；
（2）	提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出相应的提示；
（3）	直到猜对为止，并给出提示。
（提示及要求：1，要求使用C++的输入输出方式（cin, cout），不能使用C语言的printf等；2，注意检查输入的合法性）*/

#include <iostream>
using namespace std;
int main()
{
	float price;
	int answer = rand() % 1000 + 1;
	cout << "please have your first time guess:" << endl;
	cin >> price;
	if ((int)price != price)
	{
		cout << "please input integer!" << endl;
		cin.clear();
		cin >> price;
	}
	if (price < 0 || price>1000)
	{
		cout << "Your guess is illegal!" << endl;
	}
	while (price != answer)
	{
		if (price > answer)
		{
			cout << "Too high! ";
		}
		else cout << "Too low! ";
		cout << "Plaese guess again:" << endl;
		cin >> price;
		if ((int)price != price)
		{
			cout << "please input integer!" << endl;
			cin >> price;
		}
		if (price < 0 || price>1000)
		{
			cout << "Your guess is illegal!" << endl;
			cin >> price;
		}
	}
	cout << "Good guess! The answer is " << price;
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
