#include <iostream>
#include <string>
using namespace std;
int Change1(string& s, int& er)
{
	size_t pos1, pos2, pos3;
	pos1 = s.find('(', 0);
	pos2 = s.find('(', pos1+1);
	pos3 = s.find(')', 0);
	if (pos1 == -1||pos3==-1)
		return 0;
	if (pos2 < pos3 && pos2 != -1)
	{
		er = 1;
		return 0;
	}
	else
	{
		s.erase(pos1, pos3 - pos1+1);
		return 1;
	}
}
int Change(string& s, int& er)
{
	int first, second;
	first = s.find('(', 0);
	second = s.find(')', 0);
	if (first != -1 && second != -1)
	{
		while (Change1(s, er));
	}
	else er = 2;
	return er;
}
int main()
{
	string str;
	int error;
	cout << "Enter string:" << endl;
	getline(cin, str);
	Change(str, error);
	if (error == 1)
		cout << "inside some brackets there are others" << endl;
	else if (error == 2)
		cout << "there is no pair of parentheses";
	else cout << "Modified string: " << str << endl;
	return 0;
}