#include <iostream>
#include "String.h"
#include <cstring>
using namespace std;

void testStringFunctions() {
    String str1, str2, result;
    int choice;

    do {
        cout << "请选择要测试的功能：" << endl;
        cout << "1. 输入字符串" << endl;
        cout << "2. 输出字符串" << endl;
        cout << "3. 插入字符串" << endl;
        cout << "4. 查找字符串" << endl;
        cout << "5. 字符串拼接" << endl;
        cout << "6. 清空字符串" << endl;
        cout << "0. 退出" << endl;
        cout << "输入你的选择: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "请输入一个字符串: ";
            cin >> str1;
            break;

        case 2:
            cout << "当前字符串为: ";
            str1.Output(cout);
            cout << endl;
            break;

        case 3: {
            char insertStr[1024];
            cout << "请输入要插入的字符串: ";
            cin >> insertStr;
            /*cout << "size:" << strlen(insertStr) << " " << str1.length() << endl;*/  
            int position;
            cout << "请输入插入位置: ";
            cin >> position;
            str1.insert(position, insertStr);
            /*cout << "size:" << str1.length()<<endl;*/    //length大小改变表示插入成功  可能是output的问题
            // 已查明，output使用size进行循环，而insert函数没有改变size，要么output改为使用strlen循环，要么想办法output改变size
            break;
        }

        case 4: {
            char findStr[1024];
            cout << "请输入要查找的字符串: ";
            cin >> findStr;
            String strToFind(findStr);
            int position = str1.find(strToFind);
            if (position != -1) {
                cout << "字符串 '" << findStr << "' 在位置 " << position << " 找到。" << endl;
            }
            else {
                cout << "字符串 '" << findStr << "' 未找到。" << endl;
            }
            //find函数疑似写错了
            break;
        }

        case 5: {
            char appendStr[1024];
            cout << "请输入要拼接的字符串: ";
            cin >> appendStr;
            str1.append(appendStr);
            cout << "拼接后的字符串为: ";
            str1.Output(cout);
            cout << endl;
            break;
        }

        case 6:
            str1.clear();
            cout << "字符串已清空。" << endl;
            break;

        case 0:
            cout << "退出程序。" << endl;
            break;

        default:
            cout << "无效的选择，请重新输入。" << endl;
        }
    } while (choice != 0);
}

int main() {
    testStringFunctions();
    return 0;
}
