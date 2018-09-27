#include <iostream>
#include <string>
using namespace std;

//char* 和 string转换
void test1()
{
    //string类型转换为char*字符串
    string s = "abc";
    const char *s1 = s.c_str();
    cout << s1 << endl;

    //char *类型转为string类型字符串
    char* s2 = "abcde";
    string s3(s2);
    cout << s3 << endl;
}


void test2()
{
    string s1 = "abcdefg";
    for(unsigned int i = 0; i < s1.size(); ++i)
        cout << s1[i] << "  ";
    cout << endl;

    for(unsigned int i = 0; i < s1.size(); ++i)
        cout << s1.at(i) << "  ";
    cout << endl;

    try
    {
        cout << s1.at(100) << endl;//会抛出异常
        //cout << s1[100] << endl; //不会抛出异常
    }
    catch(...)
    {
        cout << "访问越界" << endl;
    }
    
}

//string容器连接的操作
void test3()
{
    string s1 = "aaa";
    string s2 = "bbb";
    string s3 = s1 + s2;
    cout << s3 << endl;

    //成员方法append
    s1.append(s2);
    cout << s1 << endl;
}

//string查找和替换 比较
void test4()
{
    string s = "abcdefiiicdef";
    string target = "cd";
    char * target1 = "ef";
    
    cout << s.find(target) << endl;//查找字符第一次出现位置的下标 开始---[0]
    cout << s.find(target1) << endl;

    cout << s.rfind(target) << endl;//查找字符最后一次出现的下标
    cout << s.rfind(target1) << endl;

    string s1 = "llll";
    s.replace(0, 2, s1);
    cout << s << endl;
}

//string比较 子串 插入和删除
void test5()
{
    //比较
    string s1 = "abc";
    string s2 = "abcd";

    int ret = s1.compare(s2);
    if(ret == 1)
        cout << "s1 > s2" << endl;
    else if(ret == -1)
        cout << "s1 < s2" << endl;
    else if(ret == 0)
        cout << "s1 = s2" << endl;
    
    
    //子串
    string s3 = "abcdefg";
    string s4 = s3.substr(0, 2);
    cout << s4 << endl;

    //插入和删除
    string s5 = "abcd";
    s5.insert(0, "ppppp");
    s5.insert(s5.size() - 1, "qqqqq");
    cout << s5 << endl;

    s5.erase(0,3);//前闭后开
    cout << s5 << endl;

}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

