// charInvert.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char inStr[1000];
	gets_s(inStr);

	int strLen = strlen(inStr);
	printf("输入字符串长度%d\n", strLen);
	
	for (int i = 0; i < strLen; i++)
	{
		if (inStr[i] == 32) 
		{
			inStr[i] = '0'; 
		}

		else if (inStr[i] >= 'A' && inStr[i] <= 'Z')
		{
			inStr[i] += 32;
		}

	}
	for (int n = (strLen-1); n>=0; n--)
	{
		printf("%c", inStr[n]);
	}
    
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单


