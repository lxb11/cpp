#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Teacher
{
public:
    Teacher(char* name, int age)
    {
        int len = strlen(name);
        this->name = new char[len + 1];//在堆分配内存
        strcpy(this->name, name);

        this->age = age;
    }

    Teacher(const Teacher& another)
    {
        if(another.name != NULL)
        {
            int len = strlen(another.name);
            this->name = new char[len + 1];
            strcpy(this->name, another.name);
        }
        this->age = another.age;
    }

    Teacher& operator=(const Teacher& another)
    {
        if(this->name != NULL)
        {
            delete[] this->name;
        }

        if(another.name != NULL)
        {
            int len = strlen(another.name);
            this->name = new char[len + 1];
            strcpy(this->name, another.name);
        }
        this->age = another.age;

        return *this;
    }

    ~Teacher()
    {
        if(this->name != NULL)
        {
            delete[] this->name;
        }
        this->age = 0;
    }

    char* name;
    int age;

};


//测试函数 深拷贝和浅拷贝
void test1()
{
    Teacher t1("chris", 20);
    vector<Teacher> vec;
    vec.push_back(t1);


}

int main()
{
    cout << "---------test1-----------" << endl;
    test1();
    return 0;
}

