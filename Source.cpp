#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Find3(char* s)
{
	int k = 0;
	size_t pos = 0;
	char* t;
	while (t = strchr(s + pos, ','))
	{
		k++;
		if (k == 3)
			break;
		pos++;
	}
	return pos;
}
void Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, ','))
	{
		pos2 = p - s + 1;
		strncat(t, s + pos1, pos2 - pos1 - 1);
		strcat(t, "**");
		pos1 = pos2;
	}
	strcat(t, s + pos1);
	strcpy(s, t);
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "Index of the third comm: " << Find3(str) << endl;
	Change(str);
	cout << "Modified string: " << str << endl;
	return 0;
}