#include <iostream>
using std::cout;
#include <string>  // stoi(string); cin >> string require this header;
using std::string; // c_str()

void ExceptionFunc(string &strExcptn, int &option)
{
	const char *strExcptnChar = strExcptn.c_str();
	int indx = 0;
	while (*(strExcptnChar + indx) != '\0')
	{
		if (!isdigit(*(strExcptnChar + indx))) // !isspace(*strExcptnChar))
		{
			cout << "In input not found pure positive digit(s).\n";
			option = -1;
			return;
		}
		indx++;
	}
	if (*strExcptnChar != '\0')
		option = stoi(strExcptn);
	else
	{
		cout << "In input not found pure positive digit(s).\n";
		option = -1;
	}
}

void ExceptionFunc(string &strExcptn, float &option)
{
	const char *strExcptnChar = strExcptn.c_str();
	int indx = 0;
	while (*(strExcptnChar + indx) != '\0')
	{
		if (!isdigit(*(strExcptnChar + indx)))
		{
			cout << "In input not found pure positive digit(s).\n";
			option = -1;
			return;
		}
		indx++;
	}
	if (*strExcptnChar != '\0')
		option = stof(strExcptn);
	else
	{
		cout << "In input not found pure positive digit(s).\n";
		option = -1;
	}
}
