#include <filesystem>
#include <sstream>
#include "file-splitter.h"
namespace fs = std::filesystem;

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

		int file_splitter::open(const std::string& _file, int splite_size, pcall pf)
		{
			std::stringstream ss;

			int64_t countn = 0;
			int current_len = 0;

			fs::path fp = _file;
			if (false == fs::exists(fp))
			{
				return -1;
			}
			auto err = std::error_code{};

			countn = fs::file_size(fp, err);

			ss.str("");
			ss << "file size:" << countn << std::endl;
			std::cout << ss.str() << std::endl;

			while (0 < countn)
			{
				if (countn < splite_size)
				{
					pf("a", countn);
					break;
				}
				current_len = splite_size;
				countn -= splite_size;
				pf("b", current_len);
			}

			return 0;
		}

		int file_splitter::close()
		{
			return 0;
		}

	};
};


