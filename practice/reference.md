## 引用

1. 引用在cpp中就是一个指针常量  Type & name ==== Type※ const name
2. 在理解引用的时候，可以引用理解为一个变量的别名

```
strut TypeA
{
    int *a;
}

struct TypeB
{
    char &a;
}

cout << sizeof(TypeA) << endl;
cout << sizeof(TypeB) << endl;

void motifyA(int &a)
{
    a = 1000;//a实际上是一个常量指针，
    //但是如果你给一个a赋值，编译器会有一个隐形的操作*

}

int main()
{
    motifyA(a);//int value----> int &a = value;给引用指定指向那个变量的时候，
    //编译器又有一个隐形的操作， a = &value;

}


```
## 引用作为函数返回值

```
int &getA()//返回值是a的别名
{
    int a = 10;
    return a;
}

void test()
{
    int &r_a = getA();//没有值拷贝动作，禁止
}
```
