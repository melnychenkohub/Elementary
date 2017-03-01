#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;
#include "Exercises.h"
#include "ExceptionFunc.h"

int main(void)
{
	int option = 0;
	string strExcptn;
	do
	{
		cout << "Enter the option of the exercise (number from 1 to 20 inclusive, 0 for EXIT): ";
		getline(cin, strExcptn); // read symbols to enter;
		ExceptionFunc(strExcptn, option);
		if (option <= 0 || option > 20)
		{
			if (option)
			{
				cout << "Incorrect input. Try again.\n";
				continue;
			}
			else
				break;
		}
		switch (option)
		{
		case 1:
			Var1();
			break;
		case 2:
			Var2();
			break;
		case 3:
			Var3();
			break;
		case 4:
			Var4();
			break;
		case 5:
			Var5();
			break;
		case 6:
			Var6();
			break;
		case 8:
			Var8();
			break;
		case 9:
			Var9();
			break;
		default:
			cout << "This variant of exercises in work.\n";
		}
	} while (option);
	cout << "Bye.\n";
	system("pause");
	return 0;
}
