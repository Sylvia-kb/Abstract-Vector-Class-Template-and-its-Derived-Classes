#include <iostream>
#include "String.h"
using namespace std;
int main()
{

	String str10("Hello"), str20(str10), str30;
	cout << "ԭʼ���ݣ�˫������������ӵģ���" << endl;
	cout << "str10 = \"" << str10
		<< "\"\nstr20 = \"" << str20
		<< "\"\nstr30 = \"" << str30 << "\"" << endl;

	String str1 = "Hello", str2 = str1, str3;
	// ת������		�������� 	Ĭ�Ϲ���
	cout << "ԭʼ���ݣ�˫������������ӵģ���" << endl;
	cout << "str1 = \"" << str1
		<< "\"\nstr2 = \"" << str2
		<< "\"\nstr3 = \"" << str3 << "\"" << endl;

	str3 = str2;				// ��ֵ����
	str1 = "C++ program.";
	str2 = str3 + ", world!";	// ƴ������
	cout << "str1 = \"" << str1
		<< "\"\nstr2 = \"" << str2
		<< "\"\nstr3 = \"" << str3 << "\"" << endl;

	cout << "\n�����������ݣ����������ȵ�0��..." << endl;
	str1.resize(0);
	str2.resize(0);
	str3.resize(0);
	cout << "str1 = \"" << str1
		<< "\"\nstr2 = \"" << str2
		<< "\"\nstr3 = \"" << str3 << "\"" << endl;

	return 0;
    
}