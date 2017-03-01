#include <ctime>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::cin;
#include <string>
#include "ExceptionFunc.h"

void FillArr(float **const arr, const int &row, const int &column)
{
	void MenuFuncFill(int &choiceFill);
	int choiceFill = 0;
	MenuFuncFill(choiceFill);
	int i, j;
	if (1 == choiceFill)
	{
		srand(time(0));
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				*(*(arr + i) + j) = (rand() % 1000 / 1000.0) + rand() % 100; // number = float part (.000 - .999) number + int part (0 - 99) number;
				*(*(arr + i) + j) *= rand() % 3 ? 1 : -1; // '+' or '-' signed;
			}
		}
	}

	if (2 == choiceFill)
	{
		string strExcptn;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				cout << "Enter float value for arr[" << i << "][" << j << "] element of array: ";
				getline(cin, strExcptn);
				ExceptionFunc(strExcptn, *(*(arr + i) + j));
			}
		}
	}
}

void FillArr(int **const arr, const int &row, const int &column)
{
	void MenuFuncFill(int &choiceFill);
	int choiceFill = 0;
	MenuFuncFill(choiceFill);
	int i, j;
	if (1 == choiceFill)
	{
		srand(time(0));
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				*(*(arr + i) + j) = rand() % 100; // number = int part (0 - 99) number;
				*(*(arr + i) + j) *= rand() % 3 ? 1 : -1; // '+' or '-' signed;
			}
		}
	}

	if (2 == choiceFill)
	{
		string strExcptn;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				cout << "Enter int value for arr[" << i << "][" << j << "] element of array: ";
				getline(cin, strExcptn);
				ExceptionFunc(strExcptn, *(*(arr + i) + j));
			}
		}
	}
}

void MenuFuncFill(int &choiceFill)
{
	cout << "\nFunc filling of array:\n";
	string strExcptn;
	do
	{
		cout << "1. Function determines random values (from -99 to 99);\n";
		cout << "2. Manual input values;\n";
		cout << "Enter your choice: ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, choiceFill);
		if (choiceFill < 1 || choiceFill > 2)
		{
			cout << "Incorrect input. Try again.\n";
		}
	} while (choiceFill < 1 || choiceFill > 2);
}