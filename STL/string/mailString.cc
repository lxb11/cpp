#include <iostream>
#include <string>
using namespace std;

//判断字符串是否是邮箱
int emailTest(string email)
{
    int pos1 = email.find("@");
    int pos2 =email.find(".");

    if(pos1 == -1 || pos2 == -1)
    {
        cout << "邮箱中不包含@或者. !" << endl;
        return 0;
    }

    if(pos1 > pos2)//@ 在 . 之前
    {
        cout << "输入的邮箱不合法" << endl;
        return 0;
    }

    string username = email.substr(0, pos1);
    
    string::iterator pStart = username.begin();
    string::iterator pEnd = username.end();

    while(pStart != pEnd)
    {
        if(*pStart < 97 || *pStart > 122)
        {
            cout << "输入的字符包含非小写字母" << endl;
            return 0;
        }
        ++pStart;
    }
    cout << "邮箱合法" << endl;
    return 0;
}

int main()
{
    string email = "abc123@hotmail.com";
    string email1 = "abc@hotmail.com";
    emailTest(email);
    emailTest(email1);

    return 0;
}

