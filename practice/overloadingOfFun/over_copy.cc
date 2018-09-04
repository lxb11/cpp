#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Student
{
public:
    Student(int id, char* name)
    {
        this->id = id;

        int len = strlen(name);
        this->name = (char*)malloc(len + 1);//将name再对上开辟一个空间
        strcpy(this->name, name);
    }
    ~Student()
    {
        if(this->name != NULL)
        {
            delete[] this->name;
            this->name = NULL;
            this->id = 0;
        }
    }

    //防止浅拷贝
    Student(const Student& another)
    {
        this->id = another.id;
        int len = strlen(another.name);
        this->name = (char*)malloc(len + 1);
        strcpy(this->name, another.name);
    }
    
    Student& operator=(const Student& another)
    {
        if(this->name != NULL)
        {
            //原来有数据,需要释放
            delete []name;
            this->name = NULL;
            this->id = 0;
        }
        this->id = another.id;
        int len = strlen(another.name);
        this->name = (char*)malloc(len + 1);
        strcpy(this->name, another.name);
        return *this;
    }

    void printS()
    {
        cout << "id:" << this->id << endl; 
        cout << "name:" <<this->name << endl;
    }
private:
    int id;
    char *name;//准备在对上开辟空间
};

int main()
{

    Student s1(1, "zhangsan");
    Student s2(s1);
    s2.printS();

    Student s3(3, "chrislv");
    s3 = s1;

    s3.printS();

    return 0;
}

