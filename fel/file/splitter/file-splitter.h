﻿// splitter
// create: 2023-8-12 16:06:20
// g++ -o test.exe -std=c++20 -g

#include <iostream>
#include <string>

namespace fel
{
	namespace file
	{
		typedef int(*pcall)(const char*, int);

		class file_splitter
		{
		public:
			file_splitter();
			~file_splitter();

			int open(const std::string& _file, pcall pf);
			int close();
		};
	};
};
