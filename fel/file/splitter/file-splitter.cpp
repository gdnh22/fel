// 实现string类2.0
// create: 2023-06-11 20:33:59
// g++ -o test.exe -std=c++20 -g

#include <iostream>
#include <cstring>

// 成员变量 m_pstr m_len 适合笔试
class wfstring
{
public:
	wfstring() :m_pstr(new char[1]), m_len(0) {
		*m_pstr = '\0';
	}

	wfstring(const char* pData) :m_pstr(nullptr), m_len(0)
	{
		if (nullptr != pData)
		{
			m_len = strlen(pData);
			m_pstr = new char[m_len + 1];
			strcpy(m_pstr, pData);  // <cstring>
		}
		else
		{
			m_pstr = new char[1];
			*m_pstr = '\0';
		}
	}

	wfstring(const wfstring& other)
	{
		m_len = other.m_len;
		m_pstr = new char[m_len + 1];
		strcpy(m_pstr, other.m_pstr);
	}

	~wfstring() noexcept
	{
		delete[] m_pstr;
	};

	size_t length() const
	{
		return m_len;
	}

	const char* c_str() const {
		return m_pstr;
	}

	wfstring& operator=(const wfstring& other)
	{
		if (this != &other)
		{
			delete[] m_pstr;
			m_len = other.m_len;
			m_pstr = new char[m_len + 1];
			strcpy(m_pstr, other.m_pstr);
		}
		return *this;
	}

	// +=
	wfstring& operator+=(const wfstring& other)
	{
		int new_len = m_len + other.m_len;

		char* ptemp = new char[new_len + 1];

		strcpy(ptemp, m_pstr);
		strcpy(ptemp + m_len, other.m_pstr);

		delete[] m_pstr;

		m_pstr = ptemp;

		m_len = new_len;
		return *this;
	}

	char& operator[](int index)
	{
		return m_pstr[index];
	}

	const char& operator[](int index) const
	{
		return m_pstr[index];
	}

	friend bool operator==(const wfstring& lhs, const wfstring& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) == 0;
	}

	friend bool operator!=(const wfstring& lhs, const wfstring& rhs)
	{
		return strcmp(lhs.c_str(), rhs.c_str()) != 0;
	}

	friend std::ostream& operator<<(std::ostream& os, const wfstring& str)
	{
		return os << str.c_str();
	}

private:
	char* m_pstr;
	int m_len;
};


int main()
{
	int ambiguous_bu_que_ding = 0;
	wfstring s1;

	const char test[] = "is ambiguous";

	s1 = test;  // =


	std::cout << "Hello World! ====> s1.c_str() ====> " << s1.c_str() << std::endl;

	std::cout << "Hello World! ====> s1[3] ====> " << s1[3] << std::endl;

	std::cout << "Hello World! ====> " << s1 << std::endl;

	wfstring s2("what ");

	s2 += s1;

	wfstring s3(s2);

	std::cout << "Hello World! s2 ====> [" << s2 << std::endl;

	std::cout << "Hello World! s3!=s2 ====> [" << (s3 != s2) << std::endl;

	return ambiguous_bu_que_ding;
}
