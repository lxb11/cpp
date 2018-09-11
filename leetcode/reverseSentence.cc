#include <iostream>
#include <cstring>
using namespace std;

void Reverse(char* pBegin, char* pEnd)
{
    if(pBegin == NULL ||  pEnd == NULL)
        return;

    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        ++pBegin;
        --pEnd;
    }
}

char* ReverseSentence(char* sentence)
{
    if(sentence == NULL)
        return NULL;
    char* pBegin = sentence;
    int length = strlen(sentence);
    char* pEnd = sentence + length - 1;
    Reverse(pBegin, pEnd);

    pBegin = pEnd = sentence;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')
        {
            ++pBegin;
            ++pEnd;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
        {
            ++pEnd;
        }
    }
    return  sentence;
}

char* LeftRotateString(char* pStr, int n)
{
    if(pStr == NULL)
        return NULL;
    int length = strlen(pStr);
    if(length > 0 && n > 0 && n < length)
    {
        char* pFirstStart = pStr;
        char* pFirstEnd = pStr + n - 1;
        char* pSecondStart = pStr + n;
        char* pSecondEnd = pStr + length - 1;

        //反转字符串的前面n个字符
        Reverse(pFirstStart, pFirstEnd);
        //反转字符串的后面部分
        Reverse(pSecondStart, pSecondEnd);
        //反转整个字符串
        Reverse(pFirstStart, pSecondEnd);
    }

    return pStr;
}

void test1()
{
    cout << "test1()---------" << endl;
    char sentence[] = "i am a student";
    cout << sentence << endl;
    cout <<"反转之后......" << endl;
    cout << ReverseSentence(sentence) << endl;
}

void test2()
{
    cout << "test2()---------" << endl;
    char sentence[] = "i";
    cout << sentence << endl;
    cout <<"反转之后......" << endl;
    cout << ReverseSentence(sentence) << endl;
}

void test3()
{
    cout << "test3()---------" << endl;
    char sentence[] = "abcdefg";
    cout << sentence << endl;
    cout <<"左旋转之后......" << endl;
    cout << LeftRotateString(sentence, 2) << endl;
    
}

void test4()
{
    cout << "test4()---------" << endl;
    char sentence[] = "abcdefg";
    cout << sentence << endl;
    cout <<"左旋转之后......" << endl;
    cout << LeftRotateString(sentence, 0) << endl;
    
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}

