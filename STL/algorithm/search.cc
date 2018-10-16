#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//find
void test1()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    v.push_back(8);

    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if(pos == v.end())
    {
        cout << "没找到：" << endl;
    }
    else
    {
        cout << "找到：" << *pos << endl;
    }
}


class Student
{
public:
    Student(int id, int age):_id(id), _age(age){}
    int _id;
    int _age;

    bool operator==(const Student& s)
    {
        if(this->_id == s._id && this->_age == s._age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//查找对象
void test2()
{
    vector<Student> v;
    Student s1(1, 20), s2(2, 22), s3(3, 23);
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    vector<Student>::iterator pos = find(v.begin(), v.end(), s2);
    if(pos == v.end())
    {
        cout << "没找到：" << endl;
    }
    else
    {
        cout << "找到：" << pos->_id << "  " << pos->_age << endl;
    }
    
}

//find_if

struct mycompare03
{
    bool operator()(int v)
    {
        if(v > 6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

//find_if  查找满足条件的第一个元素
void test3()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    v.push_back(8);

    vector<int>::iterator pos = find_if(v.begin(), v.end(), mycompare03());
    
    if(pos == v.end())
    {
        cout << "没找到：" << endl;
    }
    else
    {
        cout << "找到：" << *pos << endl;
    }
}

//adjacent_find 查找相邻重复元素，并返回第一个重复的元素出现的位置
void test4()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(5);
    v.push_back(3);
    v.push_back(3);
    v.push_back(8);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    
    if(pos == v.end())
    {
        cout << "没找到：" << endl;
    }
    else
    {
        cout << "找到：" << *pos << endl;
    }
    
}

//count  count_if

struct mycompare05
{
    bool operator()(int v)
    {
        if(v > 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

void test5()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(7);
    v.push_back(1);
    
    cout << count(v.begin(), v.end(), 2) << endl;

    //count_if
    count_if(v.begin(), v.end(), mycompare05());
    
}

int main()
{
    cout << "-----------test1-------------" << endl;
    test1();
    cout << "-----------test2-------------" << endl;
    test2();
    cout << "-----------test3-------------" << endl;
    test3();
    cout << "-----------test4-------------" << endl;
    test4();
    cout << "-----------test5-------------" << endl;
    test5();

    return 0;
}

