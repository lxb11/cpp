#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    int (*p)(int a, int b);
    p = &max;

    printf("%d\n", p(1, 2));

    
    return 0;
}

