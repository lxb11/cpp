#include "MyVector.h"
#include <cstring>


class Teacher
{
public:
    Teacher()
    {
        this->id = 0;
        this->name = NULL;
    }

    Teacher(int id, char* name)
    {
        this->id = id;
        int len = strlen(name);
        this->name = new char[len + 1];
        strcpy(this->name, name);
    }
    
    ~Teacher()
    {
        if(this->name != NULL)
        {
            delete[] this->name;
            this->name = NULL;
            this->id = 0;
        }
    }

    //完成拷贝构造函数，实现深拷贝
    Teacher(const Teacher& another)
    {
        this->id = another.id;
        int len = strlen(another.name);
        this->name = new char[len + 1];
        strcpy(this->name, another.name);
    }

    //完成等号操作符，实现深拷贝
    Teacher& operator=(const Teacher& another)
    {
        if(this->name != NULL)
        {
            delete[] this->name;
            this->name = NULL;
            this->id = 0;
        }

        this->id = another.id;
        int len = strlen(another.name);
        this->name = new char[len + 1];
        strcpy(this->name, another.name);
        return *this;
    }

    void printTeacher()
    {
        cout << "id = " << this->id <<  "  " << "name = " << this->name << endl;
    }
    friend ostream& operator<<(ostream& os, Teacher& another);


private:
    int id;
    char* name;

};

ostream& operator<<(ostream& os, Teacher& another)
{
    another.printTeacher();
    return os;
}

void test()
{
    Teacher t1(10, "chris1");
    Teacher t2(10, "chris2");
    Teacher t3(10, "chris3");
    Teacher t4(10, "chris4");
    Teacher t5(10, "chris5");

    MyVector<Teacher> vec(5);

    vec[0] = t1;
    vec[1] = t2;
    vec[2] = t3;
    vec[3] = t4;
    vec[4] = t5;
    for(int i = 0; i < 5; ++i)
    {
        cout << vec[i] << " ";
    }

}


int main()
{
    MyVector<int> vec1(10);
    for(int i = 0; i < 10; ++i)
    {
        vec1[i] = 10 + i;
    }
    cout << "vec1-----" << endl;
    cout << vec1 << endl;
    
    
    MyVector<int> vec2(vec1);//vec2 = vec1;拷贝构造
    cout << "vec2------" << endl;
    cout << vec2 << endl;

    MyVector<int> vec3;
    vec3 = vec2;//调用 = 号赋值
    cout << "vec3------" << endl;
    cout << vec3 << endl;


    MyVector<char> vec4(10);
    for(int i = 0; i < 10; ++i)
    {
        vec4[i] = 'a' + i;
    }
    cout << "vec4-----" << endl;
    cout << vec4 << endl;
    
    MyVector<char> vec5(vec4);//vec5 = vec6;拷贝构造
    cout << "vec5------" << endl;
    cout << vec5 << endl;

    MyVector<char> vec6;
    vec6 = vec5;//调用 = 号赋值
    cout << "vec6------" << endl;
    cout << vec6 << endl;
    
    cout << "----------------------" << endl;
    test();



    return 0;
}

