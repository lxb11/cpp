#include <iostream>
#include <cstdlib>
using namespace std;

//重载的new和delete 虽然说使用malloc和free实现的，但是也会调用对象的构造和析构
class A
{
public:
    A()
    {
        cout << "无参构造函数调用" << endl;
    }

    A(int a)
    {
        this->a = a;
        cout << "有参数构造函数的调用" << endl;
    }

    void* operator new(size_t size)
    {
        cout << "重载new操作符" << endl;
        return malloc(size);
    }

    void operator delete(void* p)
    {
        cout << "重载了一个delete操作符" << endl;
        if(p != NULL)
            free(p);
    }
    
    void* operator new[](size_t size)
    {
        cout << "重载了一个new[]操作符" << endl;
        return malloc(size);
    }

    void operator delete[](void* p)
    {
        cout << "重载了一个delete[]操作符" << endl;
        if(p != NULL)
            free(p);
    }

    ~A()
    {
        cout << "析构函数调用" << endl;
    }
private:
    int a;


};

int main()
{
    int *p = new int;//在堆上开辟一个int
    *p = 20;
    cout << *p << endl;
    delete p;
    
    A *ap = new A;//调用我们的重载new
    delete ap;

    int *array_p = new int[10];//开辟一个数组 new[]
    delete[] array_p;

    A *array_ap = new A[10];//开辟了10个A对象，数组首地址array_ap
    delete[] array_ap;


    
    return 0;
}

