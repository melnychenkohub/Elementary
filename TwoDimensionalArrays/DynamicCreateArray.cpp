#include <iostream>
using std::cout;
using std::cin;
#include <string>
#include "ExceptionFunc.h"

float **const DynamicCrteFltArr(int &row, int &column)
{
	void MenuFuncCreateTwo(int &row, int &column);
	MenuFuncCreateTwo(row, column);
	float **const arr = new float *[row];
	int i;
	for (i = 0; i < row; i++)
	{
		*(arr + i) = new float[column];
	}
	return arr;
}

int **const DynamicCrteIntArr(int &row, int &column)
{
	void MenuFuncCreateTwo(int &row, int &column);
	MenuFuncCreateTwo(row, column);
	int **const arr = new int *[row];
	int i;
	for (i = 0; i < row; i++)
	{
		*(arr + i) = new int[column];
	}
	return arr;
}

float *const DynamicCrteFltArr(int &size)
{
	void MenuFuncCreateOne(int &size);
	MenuFuncCreateOne(size);
	float *const arr = new float[size];
	return arr;
}

int *const DynamicCrteIntArr(int &size)
{
	void MenuFuncCreateOne(int &size);
	MenuFuncCreateOne(size);
	int *const arr = new int[size];
	return arr;
}

void MenuFuncCreateTwo(int &row, int &column)
{
	cout << "\n\nFunc dynamic memory allocation for two-dimensional array:\n";
	string strExcptn;
	do
	{
		cout << "Enter row (from 1 to 100 inclusive): ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, row);
		if (row <= 0 || row >= 101)
		{
			cout << "Incorrect input. Try again.\n";
		}
	} while (row <= 0 || row >= 101);
	
	do
	{
		cout << "Enter column (from 1 to 100 inclusive): ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, column);
		if (column <= 0 || column >= 101)
		{
			cout << "Incorrect input. Try again.\n";
		}
	} while (column <= 0 || column >= 101);
}

void MenuFuncCreateOne(int &size)
{
	cout << "\n\nFunc dynamic memory allocation for one-dimensional array:\n";
	string strExcptn;
	do
	{
		cout << "Enter size of array (from 1 to 100 inclusive): ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, size);
		if (size <= 0 || size >= 101)
		{
			cout << "Incorrect input. Try again.\n";
		}
	} while (size <= 0 || size >= 101);
}

long double *const DynamicCrteLDblArr(const int &size)
{
	long double *const arr = new long double[size];
	return arr;
}

float *const DynamicCrteFltArr(const int &size)
{
	float *const arr = new float[size];
	return arr;
}

int *const DynamicCrteIntArr(const int &size)
{
	int *const arr = new int[size];
	return arr;
}