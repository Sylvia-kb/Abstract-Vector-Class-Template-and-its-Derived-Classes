#include <iostream>
#include "String.h"
#include <cstring>
using namespace std;
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void testString() {

    String str1, str2, result;
    int choice;
    do {
        cout << "��ѡ��Ҫ���ԵĹ��ܣ�" << endl;
        cout << "1. ���Թ��캯��" << endl;
        cout << "2. ��������" << endl;
        cout << "3. ���Բ���" << endl;
        cout << "4. ���Բ���" << endl;
        cout << "5. �������" << endl;
        cout << "6. �����쳣����" << endl;
        cout << "7.���������ຯ��" << endl;
        cout << "0. �˳�" << endl;
        cout << "�������ѡ��: ";
        input(choice);
        switch (choice) {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3: {
            test3();
            break;
        }
        case 4: {
            test4();
            break;
        }
        case 5: {
            test5();
            break;
        }
        case 6:
            test6();
            break;
        case 7:
            test7();
            break;
        case 0:
            cout << "�˳�����";
            break;
        default:
            cout << "��Ч��ѡ�����������롣" << endl;
        }
    } while (choice != 0);
}
void test1() {
    basic_vec<char>* pStr; //����ָ��
    String str1("Hello, ");
    String str2("World!");
    pStr = &str1;
    cout << "str1: ";
    pStr->Output(cout);
    pStr = &str2;
    cout << "str2: ";
    pStr->Output(cout);
    cout << endl;
}
void test2() {
    basic_vec<char>* pStr; //����ָ��
    String str1("Hello, ");
    String str2("World!");
    String str3 = str1 + str2;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
    cout << "str3 (str1 + str2): ";
    str3.Output(cout);
	cout << endl;

	

}
void test3() {
    basic_vec<char>* pStr; //����ָ��
    String str1("Hllo");
    str1.Output(cout);
	cout << endl;
    str1.insert(1, "e");
    cout << "After insert: ";
    str1.Output(cout);
}
void test4() {
    String str1("Hello");
    cout << "strΪ��";
    str1.Output(cout);
    cout << endl;
    int pos = str1.find("l");
    cout << "l��λ���ǣ�" << pos << endl;
}
void test5() {
    String str1("Hello");
    cout << "strΪ��";
    str1.Output(cout);
    cout << endl;
    cout << "str����Ϊ��" << str1.length() << endl;
    str1.clear();
    cout << "��պ󳤶�Ϊ��" << str1.length() << endl;
}
void test6() {
    try {
        String str1("Hello");
        cout << str1[5];// Ӧ���׳��쳣
    }
    catch (const char* e) {
        cout << "�׳��쳣�� " << e << endl;
    }
}
void test7() {
    cout << "ʹ�û���ָ�����Input:" << endl;
    basic_vec<char>* p;
    String str1;
    p = &str1;
    p->Input(cin);
    cout << "����Output:" << endl;
    p->Output(cout);
    cout << endl;
}

