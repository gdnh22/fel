// splitter
// create: 2023-8-12 16:06:20
// g++ -o test.exe -std=c++20 -g

#include <iostream>
#include <cstring>

namespace fel
{
	namespace file
	{
		class file_splitter
		{
		public:
			file_splitter();
			~file_splitter();

			int open();
			int close();
		};
	};
};
