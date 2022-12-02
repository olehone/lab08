#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int Find3(const string s)
{
	int k = 0;
	size_t pos = 0;
	while ((pos = s.find(',', pos)) != -1)
	{
		k++;
		if (k == 3)
			break;
		pos++;
	}
	return pos;
}
void Change(string& s)
{
	size_t pos = 0;
	while ((pos = s.find(',', pos)) != -1)
		s.replace(pos, 1, "**");
}
int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);
	cout << "Index of the third comm: " << Find3(str) << endl;
	Change(str);
	cout << "Modified string: " << str << endl;
	return 0;
}