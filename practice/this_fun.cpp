#include <iostream>
using namespace std;

class Test
{
public:
    Test(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void printT()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }

    int getA()
    {
        return this->a;
    }

    int getB()
    {
        return this->b;
    }

    Test TestAdd01(Test &t1, Test &t2)
    {
        Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());

        return temp;

    }
    Test TestAdd02(Test &t2)
    {
        //Test temp(this->getA() + t2.getA(), this->getB() + t2.getB());
        
        Test temp(this->a + t2.a, this->b + t2.b);
        return temp;

    }
    void TestAdd03(Test &t2)
    {
        this->a += t2.a;
        this->b += t2.b;
    }
    Test TestAdd04(Test &t2)
    {
        this->a += t2.a;
        this->b += t2.b;
        return *this;
    }
    Test& TestAdd05(Test &t2)
    {
        this->a += t2.a;
        this->b += t2.b;
        return *this;
    }//匿名的temp 引用 = *this
private:
    int a;
    int b;
};

//全局函数
Test TestAdd(Test &t1, Test &t2)
{
    Test temp(t1.getA() + t2.getA(), t1.getB() + t2.getB());
    
    return temp;

}

int main()
{
    Test t1(10, 20);
    Test t2(100, 200);

    Test t3 = TestAdd(t1, t2);//调用了全局函数
    t3.printT();

    Test t4 = t1.TestAdd01(t1, t2);
    t4.printT();

    Test t5 = t1.TestAdd02(t2);
    t5.printT();
    
    t1.TestAdd03(t2);
    t1.printT();

    //t1.TestAdd04(t2).TestAdd04(t2);
    t1.TestAdd05(t2).TestAdd05(t2);//这两个区别
    t1.printT();


    return 0;
}

