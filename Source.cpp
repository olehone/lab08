#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Len(const char* s, size_t& k)
{
	if (*s++ != '\0')
	{
		k++;
		Len(s, k);
	}
	return k;
}
int Find1(const char* s, const char c)
{
	int k = 0;
	int d = 0;
	int i = 0;
	Find2(s, c, i, k, d);
	return d;
}
int Find2(const char* s, const char c, int i, int& k, int& d)
{
	if (c == s[i])
		k++;
	if (k == 3)
	{
		d = i;
		return d;
	}
	if (s[i] != '\0')
	{
		Find2(s, c, i++, k, d);
	}
	return d;
}
char* Change1(char* s, const char c)
{
	size_t len = 0;
	Len(s, len);
	char* tmp = new char[len * 2 + 1];
	char* t = tmp;
	tmp[0] = 0;
	Change2(s, c, t, 0, len, 0, 0);
	Copy(s, t);
	return tmp;
}
char* Change2(char* s, const char c, char* t, int i, size_t len, size_t ti, int k)
{
	if (s[i] == ',')
	{
		t[ti++] = '*';
		t[ti++] = '*';
		i++;
		t[ti] = '\0';
	}
	else
	{
		t[ti++] = s[i++];
		t[ti] = '\0';
	}
	if (i < len)
	{
		Change2(s, c, t, i++, len, ti, k);
	}
}
char* Copy(char* s, char* c)
{
	*s++ = *c++;
	if(*c!= 0)
	{
		Copy(s, c);
	}
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "Index of the third comm: " << Find1(str, ',') << endl;
	char* dest = new char[201];
	Change1(str, ',');
	cout << "Modified string: " << str << endl;
	return 0;
}