#include "string.h"
#include "Vector.h"
#include <iostream>
void testduotai();
using namespace std;
int main() {
    int choice = 1;
    while (choice != 0) {
        cout << "1������String��" << endl;
        cout << "2������Vector��" << endl;
        cout << "3�����Զ�̬��" << endl;
        cout << "0���˳�����" << endl;
        input(choice);
        switch (choice)
        {
        case 1:testString();
            break;
        case 2:testVector();
            break;
        case 3:testduotai();
            break;
        default:cout << "��Ч���룬������" << endl;
            break;
        case 0:cout << "�˳�����" << endl;
        }
    }
    return 0;
}
void testduotai() {
    cout << "string���̬����:" << endl;
    cout << "ʹ�û���ָ�����Input:" << endl;
    basic_vec<char>* p;
    String str1;
    p = &str1;
    p->Input(cin);
    cout << "����Output:" << endl;
    p->Output(cout);
    cout << endl;
    cout << "Vector���̬����:" << endl;
    Vector<int> vecInt0;
    Vector<double> vecDouble0;
    Vector<char> vecChar0;
    for (int i = 0; i < 10; ++i) {
        vecInt0.push(i);
        vecDouble0.push(i * 1.1);
        vecChar0.push('A' + i);
    }
    basic_vec<int>* pVecInt0 = &vecInt0;
    basic_vec<double>* pVecDouble0 = &vecDouble0;
    basic_vec<char>* pVecChar0 = &vecChar0;
    cout << "��int���͵�Output: ";
    pVecInt0->Output(cout);
    cout << endl;
    cout << "��double���͵�Output: ";
    pVecDouble0->Output(cout);
    cout << endl;
    cout << "��char���͵�Output: ";
    pVecChar0->Output(cout);
    cout << endl;
    Vector<int> vecInt10;
    Vector<double> vecDouble10;
    Vector<char> vecChar10;
    cout << "��int���͵�Input: ";
    pVecInt0 = &vecInt10;
    pVecInt0->Input(cin);
    pVecInt0->Output(cout);
    cout << endl;
    cout << "��double���͵�Input: ";
    pVecDouble0 = &vecDouble10;
    pVecDouble0->Input(cin);
    pVecDouble0->Output(cout);
    cout << endl;
    pVecChar0 = &vecChar10;
    cout << "��char���͵�Output: ";
    pVecChar0->Input(cin);
    pVecChar0->Output(cout);
    cout << endl;
}