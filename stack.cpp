/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年08月26日 星期六 11时02分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define Max 10
template<typename T>
class Stack
{
    private:
    int top;
    T arr[Max];
    public:
    Stack();
    ~Stack();
    T Pop();
    void Push(T value);
    int GetNum();
};

template<typename T>
Stack<T>::Stack()
{
    top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
    cout<<"希构函数"<<endl;
    
}

template<typename T>
T Stack<T>::Pop()
{
    if(top == -1)
    {
        cout<<"栈空，pop异常"<<endl;
    }
    else
    {
        return arr[top--];
    }

}

template<typename T>
void Stack<T>::Push(T value)
{
    if(top >= Max)
    {
        cout<<"栈溢出"<<endl;
    }
    else
    {
        arr[++top] = value;
    }
}
template<typename T>
int Stack<T>::GetNum()
{
    return top + 1;
}

int tentotwo(int n)
{
    if(n == 0)
    {

    }
    else
    {
        int m = n % 2;
        tentotwo(n / 2);
        cout<<m;
    }
}
int main()
{
    tentotwo(10);
   cout<<endl; 

    Stack<int>  a;
    int num = 10;
    while(num != 0)
    {
        a.Push(num % 2);
        num  = num / 2;
    }
    while(a.GetNum())
    {
        cout<<a.Pop();
    }
    cout<<endl;

    /*Stack<int>  a;
    a.Push(1);
    a.Push(2);
    cout<<a.GetNum()<<endl;
    cout<<a.Pop()<<endl;
    cout<<a.Pop()<<endl;
*/
    return 0;
}
