#include <iostream>
#include <list>
using namespace std;

void printList(list<int>& li)
{
    for(list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << "  ";
    }
    cout << endl;

}

//list容器初始化
void test0()
{
    list<int> mylist1;//默认构造
    list<int> mylist2(10, 5);//带参数的构造函数
    list<int> mylist3(mylist2.begin(), mylist2.end());//带参数的构造函数
    list<int> mylist4(mylist3);//拷贝构造函数

}

//list数据元素插入和删除操作
void test1()
{
    list<int> mylist1;
    mylist1.push_back(10);//尾插
    mylist1.push_back(20);
    mylist1.push_front(1);//头插
    mylist1.push_front(2);
    mylist1.push_front(2);
    mylist1.push_front(2);
    mylist1.insert(mylist1.begin(), 50);
    printList(mylist1);

    //删除
    mylist1.pop_back();
    mylist1.pop_front();
    printList(mylist1);
    mylist1.remove(2);
    printList(mylist1);
    mylist1.erase(mylist1.begin(), mylist1.end());// ==== mylist1.clear();
    cout << "size: " << mylist1.size() << endl;

}

//list大小和赋值操作
void test2()
{
    list<int> mylist1;
    cout << "size: " << mylist1.size() << endl;
    
    for(int i = 0; i < 10; ++i)
    {
        mylist1.push_back(i + 10);
    }
    cout << "size: " << mylist1.size() << endl;

    if(mylist1.empty())
    {
        cout << "空！" << endl;
    }
    else
    {
        cout << "不空！" << endl;
    }

    //赋值
    list<int> mylist2(mylist1.begin(), mylist1.end());
    printList(mylist2);
    mylist2.assign(5, 10);
    printList(mylist2);
    
    list<int> mylist3;
    mylist3 = mylist1; //operator= 赋值
    ::printList(mylist3);//代表全局的意思
    
    //reverse 翻转容器的元素
    mylist3.reverse();
    ::printList(mylist3);
}

//list排序
bool mycompare(int a, int b)
{
    return a > b;
}

class Teacher
{
public:
    Teacher(string name, int age):_name(name), _age(age){}
    string _name;
    int _age;
};

void test3()
{
    list<int> mylist1;
    mylist1.push_back(10);//尾插
    mylist1.push_back(20);
    mylist1.push_front(1);//头插
    mylist1.push_front(2);

    mylist1.sort();//默认从小到大
    printList(mylist1);
    mylist1.sort(mycompare);//回调函数
    printList(mylist1);
}

bool mycompare1(Teacher t1, Teacher t2)
{
    return t1._age > t2._age;
}
void test4()
{
    list<Teacher> mylist1;
    Teacher t1("aaa", 10), t2("bbb", 5), t3("ccc", 15);

    mylist1.push_back(t1);
    mylist1.push_back(t2);
    mylist1.push_back(t3);
    mylist1.sort(mycompare1);
    for(list<Teacher>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
    {
        cout << "姓名：" << it->_name << "  年龄：" << it->_age << endl;
    }

}



int main()
{
    cout << "-------test1----------" << endl;
    test1();
    cout << "-------test2----------" << endl;
    test2();
    cout << "-------test3----------" << endl;
    test3();
    cout << "-------test4----------" << endl;
    test4();
    return 0;
}

