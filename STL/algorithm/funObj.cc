#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


//bind1st bind2nd   绑定适配器

//第一步 需要你自定义函数对象继承父类， binary_function  unary_function

class print:public binary_function<int, int, void>
{
public:
    void operator()(int v,int v2) const
    {
        if(v > v2)
            cout << v << "  ";
    }


};

void test1()
{
    vector<int> vec;
    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i + 10);
    }

    print p;
    for_each(vec.begin(), vec.end(), bind1st(p, 15));
    cout << endl;

    for_each(vec.begin(), vec.end(), bind2nd(p, 15));
    cout << endl;

    //bind1st bind2nd 绑定适配器， 调用绑定适配器， 统统变成一元函数对象
}

//not1 not2 取反翻适配器

struct mycompare2:public unary_function<int, bool>
{
    bool operator()(int v) const
    {
        return v > 5;
    }

};

void print1(int v)
{
    cout << v << "  ";
}

void test2()
{
    vector<int> vec;
    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    vector<int>::iterator pos = find_if(vec.begin(),  vec.end(), mycompare2());//匿名对象
    if(pos != vec.end())
    {
        cout << "找到：" << *pos << endl;
    }
    else
    {
        cout << "没找到：" << endl;
    }

    mycompare2 myp2;
    pos = find_if(vec.begin(),  vec.end(), not1(myp2));
    if(pos != vec.end())
    {
        cout << "找到：" << *pos << endl;
    }
    else
    {
        cout << "没找到：" << endl;
    }

    //sort算法
    sort(vec.begin(), vec.end(), greater<int>());
    for_each(vec.begin(), vec.end(), print1);
    cout << endl;

    sort(vec.begin(), vec.end(), not2(greater<int>()));//取反适配器
    for_each(vec.begin(), vec.end(), print1);
    cout << endl;
}


//ptr_func 普通函数适配器
//对普通函数进行绑定参数
//1 需要将普通函数转化为函数对象 ptr_fun
//2 可以用bind适配器了
void print2(int v, int v2)
{
    if(v > v2)
        cout << v << "  ";
}

void test3()
{
    vector<int> vec;
    for(int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    for_each(vec.begin(), vec.end(), bind2nd(ptr_fun(print2), 5));
    cout << endl;
}

//mem_fun mem_fun_ref
//

class Teacher
{
public:
    Teacher(int id, int age):_id(id), _age(age){}
    int _id;
    int _age;

    void printTeacher() const
    {
        cout << "id:" << this->_id <<  "  age:" << this->_age << endl;
    }
};

class print3
{
public:
    void operator()(Teacher t)
    {
        cout << "id:" << t._id << "  age:" << t._age << endl;
    }
};

void test4()
{
    vector<Teacher> v;
    Teacher t1(1, 20), t2(2, 30), t3(3, 40);
    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);

    //函数对象方式
    for_each(v.begin(), v.end(), print3());
    cout << endl;
    
    //用类的成员函数来打印对象
    for_each(v.begin(), v.end(), mem_fun_ref(&Teacher::printTeacher));
    cout << endl;

    //如果你的容器中放的是类对象实体，用mem_fun_ref
    //如果你的容器放的是类对象指针，用，mem_fun
    
    vector<Teacher*> v2;
    Teacher* tt1 = new Teacher(4, 22);
    Teacher* tt2 = new Teacher(5, 33);
    Teacher* tt3 = new Teacher(6, 44);

    v2.push_back(tt1);
    v2.push_back(tt2);
    v2.push_back(tt3);

    for_each(v2.begin(), v2.end(), mem_fun(&Teacher::printTeacher));
    cout << endl;
}

int main()
{
    cout << "----------test1-------------" << endl;
    test1();
    cout << "----------test2-------------" << endl;
    test2();
    cout << "----------test3-------------" << endl;
    test3();
    cout << "----------test4-------------" << endl;
    test4();
    return 0;
}

