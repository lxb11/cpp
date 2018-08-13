#struct
```
struct student{
    int id;
    char name[32];
}

//
struct student stu1;

//cpp

student stu1;

```

#函数检测,C++编译器对函数形参传递，函数返回值作了严格的检查

```
//c,编译通过,cpp编译报错
int f(int i){
    printf("%d\n", i);
}

int test()
{
    f(1, 2, 3);
}

//c可以编译通过，cpp编译出错
fun(){

    return 3;
}


```

