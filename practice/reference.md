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
## 引用作为函数返回值,effective cpp 中建议：最好不要使用

```
int &getA()//返回值是a的别名
{
    int a = 1;
    return a;
}

int &getB()
{
    statict int b = 10;
    return b;
}
void test()
{
    //int &r_a = getA();//没有值拷贝动作，禁止
    int &r_b = getB();

    getB() = 100;//引用作为函数返回值时，函数名可以作为左值
}
```
## 指针引用

```
struct Teacher
{
    int id;
    char name[32];
}

//int getTeacher(Teacher *&pp)
int getTeacher(Teacher **pp)
{
    Teacher* p = NULL;

    p = (Teacher*)malloc(sizeof(Teacher));
    if(p = NULL)
    {
        cout << "error" << endl;
        return -1;
    }
    memset(p, 0, sizeof(Teacher));
    p->id = 30;
    strcpy(p->name, "zhang3");

    *pp = p;

    return 0;
}

//void freeTeacher(Teacher *&pp)
void freeTeacher(Teacher **pp)
{
    if(pp == NULL)
    {
        return;
    }
    Teacher *p = *pp;

    if(p != NULL)
    {
        free(p);
        *pp = NULL;
    }
}

int main()
{
    Teacher* tp = NULL;

    getTeacher(&tp);
    cout << tp->id << "," << tp->name << endl;

    freeTeacher(&tp);
}

```
