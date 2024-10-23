#include <iostream>
#include "Vector.h"  
using namespace std;

void testVector() {
    Vector<int> vec;

    int choice;
    while (true) {
        cout << "\n��ѡ��Ҫ���ԵĹ��ܣ����� 0 �˳���:\n";
        cout << "1. ���Ԫ�ص�ĩβ\n";
        cout << "2. �������һ��Ԫ��\n";
        cout << "3. �����ǰԪ��\n";
        cout << "4. ����Ƿ�Ϊ��\n";
        cout << "5. ��ȡԪ��\n";
        cout << "6. ���ƹ��캯��\n";
        cout << "7. ������Ϣ\n";
        cout << "8. �ͷ�δʹ�ÿռ�\n";
        cout << "9. ���Ԫ��\n";
        cout << "�������ѡ��: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            int element;
            cout << "����Ҫ��ӵ�Ԫ��: ";
            cin >> element;
            vec.push(element);
            cout << "Ԫ�� " << element << " �����.\n";
            break;
        }
        case 2: {
            try {
                vec.pop();
                cout << "���һ��Ԫ���ѵ���.\n";
            }
            catch (const char* msg) {
                cout << msg << endl;  // ����쳣��Ϣ
            }
            break;
        }
        case 3: {
            cout << "��ǰԪ��: ";
            vec.Output(cout);
            cout << endl;
            break;
        }
        case 4: {
            if (vec.empty()) {
                cout << "Vector �ǿյ�.\n";
            }
            else {
                cout << "Vector ���ǿյ�.\n";
            }
            break;
        }
        case 5: {
            int index;
            cout << "����Ҫ��ȡ������: ";
            cin >> index;
            try {
                cout << "�� " << index << " ��Ԫ��: " << vec.at(index) << endl;
            }
            catch (const char* msg) {
                cout << msg << endl;  // ����쳣��Ϣ
            }
            break;
        }
        case 6: {
            Vector<int> vec2(vec);  // ʹ�ø��ƹ��캯��
            cout << "ʹ�ø��ƹ��캯������ vec2.\n";
            cout << "vec2 ��Ԫ��: ";
            vec2.Output(cout);
            cout << endl;
            break;
        }
        case 7: {
            cout << "��ǰ����: " << vec.Capacity() << endl;
            break;
        }
        case 8: {
            vec.free2();
            cout << "���ͷ�δʹ�õĿռ�.\n";
            break;
        }
        case 9: {
            vec.Delete(0);  // ɾ����һ��Ԫ��
            cout << "��ɾ����һ��Ԫ��.\n";
            break;
        }
        default:
            cout << "��Ч��ѡ������������.\n";
            break;
        }
    }
}