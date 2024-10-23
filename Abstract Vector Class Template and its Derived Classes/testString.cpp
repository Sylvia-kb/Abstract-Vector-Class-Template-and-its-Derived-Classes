#include <iostream>
#include "String.h"
#include <cstring>
using namespace std;

void testStringFunctions() {
    String str1, str2, result;
    int choice;

    do {
        cout << "��ѡ��Ҫ���ԵĹ��ܣ�" << endl;
        cout << "1. �����ַ���" << endl;
        cout << "2. ����ַ���" << endl;
        cout << "3. �����ַ���" << endl;
        cout << "4. �����ַ���" << endl;
        cout << "5. �ַ���ƴ��" << endl;
        cout << "6. ����ַ���" << endl;
        cout << "0. �˳�" << endl;
        cout << "�������ѡ��: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������һ���ַ���: ";
            cin >> str1;
            break;

        case 2:
            cout << "��ǰ�ַ���Ϊ: ";
            str1.Output(cout);
            cout << endl;
            break;

        case 3: {
            char insertStr[1024];
            cout << "������Ҫ������ַ���: ";
            cin >> insertStr;
            cout << "size:" << strlen(insertStr) << " " << str1.length() << endl;
            int position;
            cout << "���������λ��: ";
            cin >> position;
            str1.insert(position, insertStr);
            cout << "�������ַ�����" << endl;
            cout << str1 << endl;
            cout << "size:" << str1.length() << endl;
            break;
        }

        case 4: {
            char findStr[1024];
            cout << "������Ҫ���ҵ��ַ���: ";
            cin >> findStr;
            String strToFind(findStr);
            int position = str1.find(strToFind);
            if (position != -1) {
                cout << "�ַ��� '" << findStr << "' ��λ�� " << position << " �ҵ���" << endl;
            }
            else {
                cout << "�ַ��� '" << findStr << "' δ�ҵ���" << endl;
            }
            break;
        }

        case 5: {
            char appendStr[1024];
            cout << "������Ҫƴ�ӵ��ַ���: ";
            cin >> appendStr;
            str1.append(appendStr);
            cout << "ƴ�Ӻ���ַ���Ϊ: ";
            str1.Output(cout);
            cout << endl;
            break;
        }

        case 6:
            str1.clear();
			cout << "str1=\""<< str1 << "\"" << endl;
            cout << "�ַ�������ա�" << endl;
            break;

        case 0:
            cout << "�˳�����" << endl;
            break;

        default:
            cout << "��Ч��ѡ�����������롣" << endl;
        }
    } while (choice != 0);
}

int main() {
    testStringFunctions();
	/*string str1("hello");
	string str2("world");
	string str3 = str1 + str2;
	cout << str3 << endl;*/

    return 0;
}