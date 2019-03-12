// 2.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
2.2 编写C++程序完成“矩阵”类以下功能：
（1）	用类来实现矩阵，定义一个矩阵的类，属性包括：
	矩阵大小，用 lines, rows（行、列来表示）；
	存贮矩阵的数组指针，根据矩阵大小动态申请（new）。
（2）	矩阵类的方法包括：
	构造函数，参数是矩阵大小，需要动态申请存贮矩阵的数组；
	析构函数，需要释放矩阵的数组指针；
	拷贝构造函数，需要申请和复制数组；
	输入，可以从cin中输入矩阵元素；
	输出，将矩阵格式化输出到cout；
	矩阵相加的函数，实现两个矩阵相加的功能，结果保存在另一个矩阵类，但必须矩阵大小相同；
	矩阵相减的函数，实现两个矩阵相减的功能，结果保存在另一个矩阵类，但必须矩阵大小相同。
（3）	定义三个矩阵：A1、A2、A3；
（4）	初始化A1、A2；
（5）	计算并输出A3 = A1加A2，A3 = A1减A2；（要求及提示：最好能实现对赋值操作符“ = ”的重载；注意检查“自赋值”、释放“旧元素”）
（6）	用new动态创建三个矩阵类的对象：pA1、pA1、pA3；
（7）	初始化pA1、pA2；
（8）	计算并输出pA3 = pA1加pA2，pA3 = pA1减pA2；
（9）	释放pA1、pA2、pA3。
*/
#include <iostream>
using namespace std;
class matrix {
private:
	int lines, rows;
	double** matrixPtr;
public:
	bool flag = false;
	matrix()
	{
		matrixPtr = new double* [lines];
		for (int i = 0; i < lines; i++)
		{
			matrixPtr[i] = new double[rows];
		}
	}
	matrix(const matrix& obj)
	{
		matrixPtr = new double*;
		*matrixPtr = *obj.matrixPtr;
	}
	void InitMatrix()
	{
		cout << "please input the matrix: " << endl;
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cin >> matrixPtr[i][j];
			}
		}
	}
	void PrintMatrix()
	{
		for (int i = 0; i < lines; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout << matrixPtr[i][j] << " ";
			}
			cout << endl;
		}
	}
	void set()
	{
		cout << "please input the number of lines and rows: " << endl;
		cin >> lines >> rows;
	}
	int getLines()
	{
		return lines;
	}
	int getRows()
	{
		return rows;
	}
	matrix operator+(const matrix& B)
	{
		matrix C;
		int Al, Ar, Bl, Br;
		Al = lines;
		Ar = rows;
		Bl = B.getLines();
		Br = B->getRows();
		if ((Al == Bl) && (Ar == Br))
		{
			C.flag = 1;
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < rows; j++)
				{
					C.matrixPtr[i][j] = this->matrixPtr[i][j] + B.matrixPtr[i][j];
				}
			}
		}
		return C;
	}
	matrix operator-(const matrix& B)
	{
		matrix C;
		int Al, Ar, Bl, Br;
		Al = lines;
		Ar = rows;
		Bl = B.getLines;
		Br = B.getRows;
		if ((Al == Bl) && (Ar == Br))
		{
			C.flag = 1;
			for (int i = 0; i < lines; i++)
			{
				for (int j = 0; j < rows; j++)
				{
					C.matrixPtr[i][j] = this->matrixPtr[i][j] - B.matrixPtr[i][j];
				}
			}
		}
		return C;
	}
	~matrix()
	{
		for (int i = 0; i < lines; i++)
		{
			delete[] matrixPtr[i];
		}
		delete[] matrixPtr;
	};
};



int main()
{
	matrix A1, A2, A3;
	A1.InitMatrix();
	A2.InitMatrix();
	A3 = A1 + A2;
	if (A3.flag == 1)
		A3.PrintMatrix();
	else cout << "A1 is not match A2";
	A3 = A1 - A2;
	if (A3.flag == 1)
		A3.PrintMatrix();
	else cout << "A1 is not match A2";
	auto pA1 = new matrix;
	auto pA2 = new matrix;
	auto pA3 = new matrix;
	pA1->InitMatrix();
	pA2->InitMatrix();
	A1 = *pA1;
	A2 = *pA2;
	if (A3.flag == 1)
		A3.PrintMatrix();
	else cout << "pA1 is not match pA2";
	A3 = A1 - A2;
	if (A3.flag == 1)
		A3.PrintMatrix();
	else cout << "pA1 is not match pA2";
	delete pA1;
	delete pA2;
	delete pA3;
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
