#include <iostream>
#include "Vector.h" 
#include"string.h"
using namespace std;
void testa();
void testb();
void testc();
void testd();
void teste(); // ���� pop ����
void testf(); // ���� push ����
void testg(); // ���� at ����
void testh(); // ���� operator[] ����
void testi(); // ���� operator+ ����
void testj(); // ���� swap ����

void testVector() {
    Vector<int> vec;

    int choice;
    while (true) {
        cout << "\n��ѡ��Ҫ���ԵĹ��ܣ����� 0 �˳���:\n";
        cout << "1. �������\n";
        cout << "2. ���������ຯ��\n";
        cout << "3. �����쳣����\n";
        cout << "4. ����insert\n";
        cout << "5. ����pop\n";
        cout << "6. ����push\n";
        cout << "7. ����at\n";
        cout << "8. �����±������\n";
        cout << "9. ���Լӷ������\n";
        cout << "10. ����swap\n";
        cout << "�������ѡ��: ";
        input(choice);

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            testa();
            break;
        }
        case 2: {
            testb();
            break;
        }
        case 3: {
            testc();
            break;
        }
        case 4: {
            testd();
            break;
        }
        case 5: {
            teste();
            break;
        }
        case 6: {
            testf();
            break;
        }
        case 7: {
            testg();
            break;
        }
        case 8: {
            testh();
            break;
        }
        case 9: {
            testi();
            break;
        }
        case 10: {
            testj();
        }
        default:

            break;
        }
    }
}
void testa() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;


    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }

    cout << "vecInt: ";
    vecInt.Output(cout);
    cout << endl;
    cout << "vecDouble: ";
    vecDouble.Output(cout);
    cout << endl;
    cout << "vecChar: ";
    vecChar.Output(cout);
    cout << endl;
}
void testb() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;


    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }
    basic_vec<int>* pVecInt = &vecInt;
    basic_vec<double>* pVecDouble = &vecDouble;
    basic_vec<char>* pVecChar = &vecChar;

    cout << "��int���͵�Output: ";
    pVecInt->Output(cout);
    cout << endl;
    cout << "��double���͵�Output: ";
    pVecDouble->Output(cout);
    cout << endl;
    cout << "��char���͵�Output: ";
    pVecChar->Output(cout);
    cout << endl;
    Vector<int> vecInt1;
    Vector<double> vecDouble1;
    Vector<char> vecChar1;
    cout << "��int���͵�Input: ";
    pVecInt = &vecInt1;
    pVecInt->Input(cin);
    pVecInt->Output(cout);
    cout << endl;
    cout << "��double���͵�Input: ";
    pVecDouble = &vecDouble1;
    pVecDouble->Input(cin);
    pVecDouble->Output(cout);
    cout << endl;
    pVecChar = &vecChar1;
    cout << "��char���͵�Output: ";
    pVecChar->Input(cin);
    pVecChar->Output(cout);
    cout << endl;

}
void testc() {
    try {
        Vector<int> vecInt;
        for (int i = 0; i < 10; ++i) {
            vecInt.push(i);
        }
        cout << "Խ���쳣���ԣ�" << endl;
        vecInt.at(100);
    }
    catch (const char* e) {
        cout << "�����쳣�� " << e << endl;
    }
}
void testd() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;


    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }
    vecInt.insert(2, 42);
    cout << "��2��λ�ò���42: ";
    vecInt.Output(cout);
    cout << endl;
    vecDouble.insert(2, 4.2);
    cout << "��2��λ�ò���4.2: ";
    vecDouble.Output(cout);
    cout << endl;
    vecChar.insert(2, 'a');
    cout << "��2��λ�ò���: ";
    vecChar.Output(cout);
    cout << endl;

}
void teste() {
    Vector<int> vecInt;
    Vector<double> vecDouble;
    Vector<char> vecChar;
    for (int i = 0; i < 10; ++i) {
        vecInt.push(i);
        vecDouble.push(i * 1.1);
        vecChar.push('A' + i);
    }
    cout << "����ǰ: ";
    vecInt.Output(cout);
    cout << endl;
    vecDouble.Output(cout);
    cout << endl;
    vecChar.Output(cout);
    cout << endl;
    vecInt.pop();
    vecChar.pop();
    vecDouble.pop();
    cout << "������: ";
    vecInt.Output(cout);
    cout << endl;
    vecDouble.Output(cout);
    cout << endl;
    vecChar.Output(cout);
    cout << endl;
}

void testf() {
    Vector<double> vecDouble;
    vecDouble.push(1.1);
    vecDouble.push(2.2);
    cout << "���Ԫ��1.1��2.2: ";
    vecDouble.Output(cout);
    cout << endl;
}

void testg() {
    Vector<char> vecChar;
    for (char c = 'A'; c <= 'E'; ++c) vecChar.push(c);
    cout << "vecChar������Ԫ�أ�" << vecChar << endl;
    cout << "����Ԫ��C: " << vecChar.at(2) << endl;
}

void testh() {
    Vector<int> vecInt;
    for (int i = 0; i < 5; ++i) vecInt.push(i);
    cout << "vecInt������Ԫ�أ�";
    vecInt.Output(cout);
    cout << endl;
    cout << "���ʵ�3��Ԫ��: " << vecInt[2] << endl;
}

void testi() {
    Vector<int> vec1, vec2;
    for (int i = 0; i < 5; ++i) {
        vec1.push(i);
        vec2.push(i * 2);
    }
    cout << "vec1:" << vec1 << " vec2:" << vec2 << endl;
    cout << "�ӷ�������: ";
    cout << vec1 + vec2 << endl;
}

void testj() {
    Vector<int> vec1, vec2;
    for (int i = 0; i < 5; ++i) vec1.push(i);
    for (int i = 5; i < 10; ++i) vec2.push(i);
    cout << "����ǰ vec1: ";
    vec1.Output(cout);
    cout << "����ǰ vec2: ";
    vec2.Output(cout);
    vec1.swap(vec2);
    cout << "������ vec1: ";
    vec1.Output(cout);
    cout << "������ vec2: ";
    vec2.Output(cout);
}