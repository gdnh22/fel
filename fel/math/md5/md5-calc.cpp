#include "md5.h"
#include "md5-calc.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>

#ifdef __linux
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif // __linux
#ifdef _MSC_VER
#include <windows.h>
#endif //_MSC_VER

namespace fel
{
	namespace math
	{
		int64_t f_size(FILE* fp)
		{
			size_t n;
			fpos_t fpos;

			if (fp == NULL)
				return -1;

			fgetpos(fp, &fpos);
			fseek(fp, 0, SEEK_END);
			n = ftell(fp);
			fsetpos(fp, &fpos);

			return n;
		}

		int64_t calc_md5_s(const char* src, char* dest)
		{
			uint64_t read_len = 0;
			int i = 0;
			char temp[8] = { 0 };
			unsigned char decrypt[16] = { 0 };
			MD5_CTX md5c;

			read_len = strlen(src);

			MD5Init(&md5c);
			MD5Update(&md5c, (unsigned char*)src, static_cast<unsigned int>(read_len));
			MD5Final(&md5c, decrypt);

			for (i = 0; i < 16; i++)
			{
				sprintf(temp, "%02x", decrypt[i]);
				if (NULL != dest)
				{
					strcat((char*)dest, temp);
				}
			}
			//printf("md5:%s\n", dest);

			return read_len;
		}

		int64_t calc_md5_f(const char* filename, size_t bf_size, char* dest)
		{
			int i = 0;
			size_t filelen = 0;
			size_t read_len = 0;
			char temp[8] = { 0 };
			unsigned char* buf = NULL;
			buf = (unsigned char*)malloc(sizeof(unsigned char) * bf_size);
			unsigned char decrypt[16] = { 0 };
			MD5_CTX md5;
			size_t lfsize = 0;
			FILE* fdf = NULL;

			fdf = fopen(filename, "rb");
			if (NULL == fdf)
			{
				printf("%s not exist\n", filename);
				if (NULL != buf)
				{
					free(buf);
					buf = NULL;
				}
				return -1;
			}

			lfsize = f_size(fdf);
			if (lfsize <= 0)
			{
				printf("Failed to count file size!\n");
				fclose(fdf);
				if (NULL != buf)
				{
					free(buf);
					buf = NULL;
				}
				return -2;
			}
			else
			{
				//	printf("file size: %zu bytes\n", lfsize);
				;
			}

			MD5Init(&md5);
			while (1)
			{
				memset(buf, 0, sizeof(unsigned char) * bf_size);
				read_len = fread(buf, sizeof(unsigned char), sizeof(unsigned char) * bf_size, fdf);
				if (read_len < 0)
				{
					fclose(fdf);
					if (NULL != buf)
					{
						free(buf);
						buf = NULL;
					}
					return -1;
				}
				if (read_len == 0)
					break;

				filelen += read_len;

				MD5Update(&md5, (unsigned char*)buf, static_cast<unsigned int>(read_len));		//2023-07-13 16:57:04，wangfeng

				//printf("[TIME USED = %6.2f MINUTES] [%zu%%]\r", (double)clock() / CLOCKS_PER_SEC / 60, filelen * 100 / lfsize);
				fflush(stdout);
			}
			//	printf("\n");

			MD5Final(&md5, decrypt);

			for (i = 0; i < 16; i++)
			{
				sprintf(temp, "%02x", decrypt[i]);
				if (NULL != dest)
				{
					strcat((char*)dest, temp);
				}
			}

			//printf("md5:%s len=%d\n", dest, filelen);
			fclose(fdf);
			if (NULL != buf)
			{
				free(buf);
				buf = NULL;
			}

			return filelen;
		}

		int64_t get_buf_md5(const char* src, int src_size, char* dst)
		{
			int read_len = 0;
			int i = 0;
			char temp[8] = { 0 };
			unsigned char decrypt[16] = { 0 };
			MD5_CTX md5c;

			//read_len = strlen(src);
			read_len = src_size;

			MD5Init(&md5c);
			MD5Update(&md5c, (unsigned char*)src, read_len);
			MD5Final(&md5c, decrypt);

			for (i = 0; i < 16; i++)
			{
				sprintf(temp, "%02x", decrypt[i]);
				if (NULL != dst)
				{
					strcat((char*)dst, temp);
				}
			}

			return read_len;
		}
	}
}