#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Len(const char* s)
{
	int k;
	for (k = 0; *s++ != '\0'; k++);
	return k;
}
int Find3(const char* s, const char c)
{
	int k = 0;
	int d = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (c == s[i])
			k++;
		if (k == 3)
		{
			d = i;
			break;
		}
	}
	return d;
}
char* Change(char* s, const char c)
{
	size_t len = Len(s);
	int k = 0;
	char* tmp = new char[len * 2 + 1];
	char* t = tmp;
	tmp[0] = 0;
	size_t i = 0;
	size_t ti = 0;
	while (i < len)
	{
		if (s[i] == ',')
		{
			t[ti++] = '*';
			t[ti++] = '*';
			i ++;
			t[ti] = '\0';
		}
		else
		{
			t[ti++] = s[i++];
			t[ti] = '\0';
		}
	}
	while (*s++ = *t++);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "Index of the third comm: " << Find3(str, ',')<< endl;
	char* dest = new char[201];
	Change(str, ',');
	cout << "Modified string: " << str << endl;
	return 0;
}