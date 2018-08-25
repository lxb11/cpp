#include <iostream>
#include <cstring>
#include <cstdlib>
using  namespace std;

class Teacher
{
public:
    Teacher(int id, char *name)
    {
        cout << "调用了构造" << endl;

        m_id = id;
        int len = strlen(name) + 1;
        m_name = (char *)malloc(len);
        strcpy(m_name, name);
    }

    //显示写一个拷贝构造函数
    //通过显示拷贝构造函数提供了深拷贝
    Teacher(const Teacher &another)
    {
        m_id = another.m_id;

        int len = strlen(another.m_name) + 1;
        m_name = (char*)malloc(len);

        strcpy(m_name, another.m_name);

    }

    ~Teacher()
    {
        //在构造函数中，已经开辟了内存，所以为了防止泄漏
        //在析构函数中，在对象销毁之前，把m_name的内存释放掉
        if(m_name != NULL)
        {
            free(m_name);
            m_name = NULL;
            cout << "释放了m_name" << endl;
        }
    }

private:
    int m_id;
    char *m_name;

};


int main()
{
    Teacher t1(1, "张三");

    Teacher t2(t1);

    return 0;
}

