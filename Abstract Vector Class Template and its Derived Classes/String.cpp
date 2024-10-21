// String.cpp
#include "String.h"
#include <cstring>

String::String(const char* str) : basic_vec<char>(strlen(str), str)
{
	str = ptr;
}

String::String(const String& Str, int pos, int n)
{
	int i, m;
	m = strlen(Str.str);
	if (pos > m)
	{
		str = new char[1];
		str[0] = '\0';
		return;
	}
	if (m - pos < n) n = m - pos;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = Str.str[pos + i];
	str[i] = '\0';
}

String::String(const char* s, int n)
{
	int i, m = strlen(s);
	if (m < n) n = m;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = s[i];
	str[i] = '\0';
}

String::String(int n, char c)
{
	int i;
	if (n < 0) n = 0;
	str = new char[n + 1];
	for (i = 0; i < n; i++)
		str[i] = c;
	str[i] = '\0';
}

String::String(const String& Str)
{
	str = new char[strlen(Str.str) + 1];
	strcpy(str, Str.str);
}

String& String::operator=(const String& Str)
{
	if (&Str == this) return *this;
	delete[] str;
	str = new char[strlen(Str.str) + 1];
	strcpy(str, Str.str);
	return *this;
}

String::~String()
{
	if (str != NULL)
		delete[] str;
}

void String::Input(istream& in)	// �����Զ���չ���������Ĺ���
{
	const int N = 1;//1024;		// Nȡ��Сֵ1��Ϊ�˵��ԣ�ʵ��ʹ��ʱȡ1024
	char buffer[N], ch;			// ���뻺����
	int i, j, k, flag;
	String temp;

	while (true)					// ���˵���Ч�ַ�ǰ�Ŀհ��ַ�
	{
		ch = in.peek();			// ͵����һ���ַ������Ƿ�Ϊ�հ��ַ�
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
			in.get(ch);			// ���ǿհ��ַ�������˵�������ȡ���ã�
		else
			break;				// ֱ�������ǿհ��ַ���������whileѭ��
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
		temp.resize(k * N + i);			// ������resize������"����������ԭ������"�Ĺ���
		for (j = 0; j < i; j++)
			temp[k * N + j] = buffer[j];// �����˷����������
	}
	*this = temp;					// �����˸�ֵ��������ֵ���㣩
}

void String::Output(ostream& out) const
{
	for (int i = 0; i < size; i++)
		out << str[i];
}












String& String::insert(int p0, const char* s)
{
	int n = strlen(str);
	if (p0 > n) p0 = n;
	char* p = new char[strlen(str) + strlen(s) + 1];
	strncpy(p, str, p0);		// ԭ�ַ������ݵĵ�һ����
	p[p0] = '\0';
	strcat(p, s);				// ����Ĳ���
	strcat(p, str + p0);			// ԭ�ַ�����ʣ�ಿ��
	delete[] str;				// �ͷ�ԭ�ַ���
	str = p;					// �������ַ������׵�ַ
	return *this;
}

String String::substr(int pos, int n) const
{
	String temp(*this, pos, n);
	return temp;
}

int String::find(const String& Str) const
{
	int i, j, m, n, flag;
	m = strlen(Str.str);
	n = strlen(str);
	if (m > n) return -1;
	for (i = 0; i < n - m; i++)
	{
		flag = 1;
		for (j = 0; j < m; j++)
			if (str[i + j] != Str.str[j])
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
	return strlen(str);
}

const char* String::c_str()
{
	return str;
}

void String::swap(String& Str)
{
	char* temp = Str.str;
	Str.str = str;
	str = temp;
}

void String::clear()
{
	*this = "\0";
}

String& String::append(const char* s)
{
	String temp(s);
	*this += temp;
	return *this;
}

String& String::erase(int pos, int n)
{
	int m;
	m = strlen(str);
	if (pos > m)
	{
		cout << "λ��Խ��,�ַ������ı�" << endl;
		return *this;
	}
	if (m - pos < n) n = m - pos;
	if (n < 0) n = 0;
	String temp1(*this, 0, pos);
	String temp2(*this, pos + n, m - pos - n);
	*this = temp1 + temp2;
	return *this;
}

char& String::operator[](int index) throw(int)	// ���ط����������
{
	int len = strlen(str);
	if (index < 0 || index >= len) throw (int)1;
	return str[index];
}


String operator+(const String& Str1, const String& Str2)
{
	String temp;
	temp.str = new char[strlen(Str1.str) + strlen(Str2.str) + 1];
	// �Զ���չ��Դ�ռ�
	strcpy(temp.str, Str1.str);
	strcat(temp.str, Str2.str);
	return temp;
}

String& String::operator+=(const String& Str)
{
	*this = *this + Str;
	return *this;
}

bool operator==(const String& Str1, const String& Str2)
{
	return strcmp(Str1.str, Str2.str) == 0;
}

bool operator!=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.str, Str2.str) != 0;
}

bool operator> (const String& Str1, const String& Str2)
{
	return strcmp(Str1.str, Str2.str) > 0;
}

bool operator>=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.str, Str2.str) >= 0;
}

bool operator< (const String& Str1, const String& Str2)
{
	return strcmp(Str1.str, Str2.str) < 0;
}

bool operator<=(const String& Str1, const String& Str2)
{
	return strcmp(Str1.str, Str2.str) <= 0;
}

ostream& operator<<(ostream& out, const String& Str)
{
	out << Str.str;
	return out;
}

istream& operator>>(istream& in, String& Str)
{
	char str[1000];
	in >> str;
	Str = str;				// ����ת�����캯�����Զ�ת�����������ø�ֵ����
	return in;
}


// ���ӵĳ�Ա����
istream& getline(istream& in, String& Str, int num, char delim)
{
	if (num <= 0) return in;

	if (Str.str != NULL) delete[] Str.str;
	Str.str = new char[num + 1];
	in.getline(Str.str, num, delim);
	return in;
}

String& String::trim()
{
	int i, j = strlen(str);

	if (j == 0) return *this;

	for (j--; j >= 0 && (str[j] == ' ' || str[j] == '\t'); j--)
		;
	str[j + 1] = '\0';
	for (i = 0; str[i] == ' ' || str[i] == '\t'; i++)
		;
	if (i > j)
	{
		delete[] str;
		str = new char[1];
		str[0] = '\0';
	}
	else
	{
		char* temp = new char[j - i + 2];
		strcpy(temp, str + i);
		delete[] str;
		str = temp;
	}
	return *this;
}
