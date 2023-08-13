// splitter-main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 完成后reward game prince of persia

#include <iostream>
#include <string>
#include <sstream>
#include "../../fel/file/splitter/file-splitter.h"
namespace ff = fel::file;

int callf(const char* p, int len)
{
	std::stringstream ss;

	ss << "=" << p << " =" << len << std::endl;
	std::cout << ss.str() << std::endl;

	return 0;
}


int main(int argc, char* argv[])
{
	//std::cout << "Hello World!\n";
	std::string file1("../txt/a.txt");


	ff::file_splitter fs;
	int split = 2;//2 5
	fs.open(file1, split, callf);

	fs.close();
	return getchar();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
