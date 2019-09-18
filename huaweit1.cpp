/**
* @brief 华为研发笔试（软件）第一题：判断输入数组是否符合排列条件
* @author 日月共明
* @date 2019-09-18
* @environment VS2017
*/ 
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int x = 0;
	vector<vector<int>> inVec;//输入二维矩阵容器
	vector<int> rowVec;//输入行容器

//-----从控制台输入待处理矩阵
	while (cin >> x)
	{
		rowVec.push_back(x);
		if (cin.get() == '\n')
		{
			inVec.push_back(rowVec);
			rowVec.clear();
		}
		if (cin.peek() == '\n')
		{
			inVec.push_back(rowVec);
			break;
		}
	}
//--------进行条件判断并输出结果
		
		for (int i = 0; i < inVec.size(); i++)
		{
			rowVec = inVec[i];
			int rowVecEnd = rowVec.size()-1;
			bool outResult = true;
//----------第一个条件：首尾为1位数，中间为2位数
			if (rowVec[0] < 10 && rowVec[rowVecEnd] < 10)
			{
				for (int j = 1; j < rowVecEnd; j++)
				{
					if (rowVec[j] <10) { outResult = false; break; }
				}
			}
//----------第二个条件：首尾2位数，中间为1位数
			else if(rowVec[0] > 9 && rowVec[rowVecEnd] > 9)
			{
				for (int j = 1; j < rowVecEnd; j++)
				{
					if (rowVec[j] > 9) { outResult = false; break; }
				}
			}
//----------第三个条件：相邻两个数位数不同			
			else if (rowVec[0] < 10)
			{
				for (int i = 1; i < rowVec.size(); i++)
				{
					if(rowVec[i]/10 < (i%2)) { outResult = false; break; }
				}

			}

			else if (rowVec[0] > 9)
			{
				for (int i = 1; i < rowVec.size(); i++)
				{
					if (rowVec[i]%2 ==0 && rowVec[i]<10) { outResult = false; break; }
					else if (rowVec[i] % 2 == 1 && rowVec[i] >9) { outResult = false; break; }
				}

			}
//----------输出处理结果
			if (i < (inVec.size() - 1))
			{
				if (outResult) { cout << "true "; }
				else { cout << "false "; }
			}
			else {
				if (outResult) { cout << "true"; }
				else { cout << "false"; }

			}
			




		}
		system("pause");//避免控制台闪退
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
