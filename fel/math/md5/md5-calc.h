/*************************************************************************
	> File Name: md5-calc.h
	> Author: Wang
	> version: 0.0.1
	> Created Time: 2023-8-13 17:47:03
 ************************************************************************/

#ifndef MD5_CALC_H
#define MD5_CALC_H

#include <iostream>

namespace fel
{
	namespace math
	{
		class md5_calc
		{
		public:
			/// <summary>
			/// 计算块的md5值
			/// </summary>
			/// <param name="src"></param>
			/// <param name="src_size"></param>
			/// <param name="dst"></param>
			/// <returns></returns>

		};

		int64_t get_buf_md5(const char* src, int src_size, char* dst);

		int64_t calc_md5_s(const char* src, char* dest);

		int64_t calc_md5_f(const char* filename, size_t bf_size, char* dest);

		/* 获取文件大小   */
		int64_t f_size(FILE* fp);
	}
}


#endif
