#include"String_class.h"

int main()
{
	MyString s("mystring");
	cout << s.c_str() << endl;

	MyString s1 = s;
	cout << s1.size() << endl;

	char *a = "hello", *b = "world";
	MyString s2(a), s3(b);

	cout << s2.c_str() << endl;
	cout << s3.c_str() << endl;

	return 0;
}