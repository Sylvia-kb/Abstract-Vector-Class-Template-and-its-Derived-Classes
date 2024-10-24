// String.cpp
#include "String.h"
#include <cstring>

String::String(const char* str) : basic_vec<char>(strlen(str),str)
{

}


void String::Input(istream& in)	// 具有自动扩展容器容量的功能
{
	const int N = 1;//1024;		// N取最小值1是为了调试，实际使用时取1024
	char buffer[N], ch;			// 输入缓冲区
	int i, j, k, flag;
	String temp;

	while (true)					// 过滤掉有效字符前的空白字符
	{
		ch = in.peek();			// 偷看下一个字符，看是否为空白字符
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
			in.get(ch);			// 若是空白字符，则过滤掉（即读取后不用）
		else
			break;				// 直到遇到非空白字符，结束本while循环
	}
	for (k = 0, flag = 1; flag == 1; k++)
	{
		for (i = 0; i < N; i++)
		{
			ch = in.peek();
			if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
			{
				flag = 0;
				break;
			}
			else
				in.get(buffer[i]);
		}
		temp.resize(k * N + i);			// 利用了resize函数的"尽量保留了原有数据"的功能
		for (j = 0; j < i; j++)
			temp[k * N + j] = buffer[j];// 利用了方括号运算符
	}
	*this = temp;					// 利用了赋值运算符（深赋值运算）
}

void String::Output(ostream& out) const
{
	for (int i = 0; i < size; i++)
		out << ptr[i];
}












String& String::insert(int p0, const char* s)
{
	int n = size;
	if (p0 > n) p0 = n;
	char* p = new char[size + strlen(s) + 1];
	strncpy(p, ptr, p0);		// 原字符串内容的第一部分
	p[p0] = '\0';
	strcat(p, s);				// 插入的部分
	p[p0 + strlen(s)] = '\0';
	strcat(p, ptr + p0);		// 原字符串的剩余部分
	size = size + strlen(s);
	delete[] ptr;				// 释放原字符串
	ptr = p;					// 保存新字符串的首地址
	return *this;
}


int String::find(const String& Str) const
{
	int i, j, m, n, flag;
	m = Str.size;
	n = size;
	if (m > n) return -1;
	for (i = 0; i < n - m; i++)
	{
		flag = 1;
		for (j = 0; j < m; j++)
			if (ptr[i + j] != Str.ptr[j])
			{
				flag = 0;
				break;
			}
		if (flag == 1)
			return i;
	}
	return -1;
}

int String::length() const
{
	return size;
}

const char* String::c_str()
{
	return ptr;
}

void String::swap(String& Str)
{
	char* temp = Str.ptr;
	Str.ptr = ptr;
	ptr = temp;
}

void String::clear()
{
	*this = "\0";
}
String& String::append(const char* s) {
	if (s == nullptr) return *this; // Handle null input

	int new_size = size + strlen(s);
	char* new_ptr = new char[new_size + 1]; // Allocate new memory

	strcpy(new_ptr, ptr); // Copy the existing string
	new_ptr[size] = '\0'; // Null-terminate the new string
	strcat(new_ptr, s);   // Append the new string

	delete[] ptr; // Free the old memory
	ptr = new_ptr; // Update the pointer to the new memory
	size = new_size; // Update the size

	return *this;
}

String operator+(const String& Str1, const String& Str2) {
	String temp;
	temp.ptr = new char[Str1.size + Str2.size + 1];
	temp.size = Str1.size + Str2.size;
	strcpy(temp.ptr, Str1.ptr);
	temp.ptr[Str1.size] = '\0';

	strcat(temp.ptr, Str2.ptr);

	return temp;
}

String& String::operator+=(const String& Str)
{
	*this = *this + Str;
	return *this;
}

bool operator==(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) == 0;
}

bool operator!=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) != 0;
}

bool operator> (const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) > 0;
}

bool operator>=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) >= 0;
}

bool operator< (const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) < 0;
}

bool operator<=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.ptr, Str2.ptr) <= 0;
}



// 附加的成员函数
istream& getline(istream& in, String& Str, int num, char delim)
{
	if (num <= 0) return in;

	if (Str.ptr != NULL) delete[] Str.ptr;
	Str.ptr = new char[num + 1];
	in.getline(Str.ptr, num, delim);
	return in;
}

String& String::trim()
{
	int i, j = strlen(ptr);

	if (j == 0) return *this;

	for (j--; j >= 0 && (ptr[j] == ' ' || ptr[j] == '\t'); j--)
		;
	ptr[j + 1] = '\0';
	for (i = 0; ptr[i] == ' ' || ptr[i] == '\t'; i++)
		;
	if (i > j)
	{
		delete[] ptr;
		ptr = new char[1];
		ptr[0] = '\0';
	}
	else
	{
		char* temp = new char[j - i + 2];
		strcpy(temp, ptr + i);
		delete[] ptr;
		ptr = temp;
	}
	return *this;
}

void input(int& op) {
	std::cin >> op;
	while (std::cin.fail())                //防止错误输入。
	{
		std::cout << "Invalid input. Please enter a number." << endl;
		std::cin.clear();            // 清理错误状态位
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 丢弃无效输入
		std::cin >> op;
	}
}