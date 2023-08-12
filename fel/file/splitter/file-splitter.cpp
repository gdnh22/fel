
#include "file-splitter.h"

namespace fel
{
	namespace file
	{

		file_splitter::file_splitter()
		{
			;
		}

		file_splitter::~file_splitter()
		{

		}

		int file_splitter::open(const std::string& _file, pcall pf)
		{
			for (auto i = 0; i < 10; i++)
			{
				pf("abc", i);
			}
			return 0;
		}

		int file_splitter::close()
		{
			return 0;
		}

	};
};


