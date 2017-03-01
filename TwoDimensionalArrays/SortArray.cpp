#include <iostream>
using std::cout;
using std::cin;
#include <string>
#include "CopyArrays.h"
#include "PrintArray.h"
#include "SwapFunc.h"
#include "DynamicDeleteArray.h"
#include "ExceptionFunc.h"

void QuickSort(float *const arr, const int &lastIndx, const int &choiceSort);
void QuickSort(int *const arr, const int &lastIndx, const int &choiceSort);
void BubbleSort(float *const arr, const int &lastIndx, const int &choiceSort);
void BubbleSort(int *const arr, const int &lastIndx, const int &choiceSort);

void SortArr(float **const arr, const int &row, const int &column)
{
	int i, j;
	int size = row * column, indx = 0;
	float *copyArr = new float[size]; // duplicate two-dimensional array;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			*(copyArr + indx++) = *(*(arr + i) + j); // copy values from two-dimensional array;
		}
	}

	void MenuChoiceFunc(int &choiceFunc);
	
	int choiceFunc = 0;
	MenuChoiceFunc(choiceFunc);
	
	void MenuFuncSort(int &choiceSort);
	
	int choiceSort = 0;
	MenuFuncSort(choiceSort);

	if (1 == choiceFunc)
		QuickSort(copyArr, (size - 1), choiceSort);
	if (2 == choiceFunc)
		BubbleSort(copyArr, (size - 1), choiceSort);
	PrintArr(copyArr, size);

	void MenuFuncCopy(int &choiceSort);
	
	MenuFuncCopy(choiceSort);
	if (1 == choiceSort)
	{
		CopyArr(arr, copyArr, row, column);
	}
	DynamicDelArr(copyArr);
}

void QuickSort(float *const copyArr, const int &lastIndx, const int &choiceSort)
{
	int i = 0, j = lastIndx, x = copyArr[lastIndx / 2];
	
	do {
		if (1 == choiceSort)
		{
			while (*(copyArr + i) > x) i++;
			while (*(copyArr + j) < x) j--;
		}
		if (2 == choiceSort)
		{
			while (*(copyArr + i) < x) i++;
			while (*(copyArr + j) > x) j--;
		}

		if (i <= j) {
			SwapFunc(*(copyArr + i), *(copyArr + j));
			i++;
			j--;
		}
	} while (i <= j);
	if (lastIndx > i)
		QuickSort(copyArr + i, lastIndx - i, choiceSort);
	if (j > 0)
		QuickSort(copyArr, j, choiceSort);
}

void BubbleSort(float *const copyArr, const int &lastIndx, const int &choiceSort)
{
	bool CmpreFunc(const float &var1, const float &var2, const int &choiceSort);
	
	int i, j;
	
	for (i = lastIndx; i >= 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (CmpreFunc(*(copyArr + j), *(copyArr + (j + 1)), choiceSort))
			{
				SwapFunc(*(copyArr + j), *(copyArr + (j + 1)));
			}
		}
	}
}

bool CmpreFunc(const float &var1, const float &var2, const int &choiceSort)
{
	if (2 == choiceSort)
	{
		return var1 > var2;
	}
	else
	if (1 == choiceSort)
	{
		return var1 < var2;
	}
	else
	{
		return 0;
	}
}

void SortArr(int **const arr, const int &row, const int &column)
{
	int i, j;
	int size = row * column, indx = 0; // duplicate two-dimensional array;
	int *copyArr = new int[size];
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			*(copyArr + indx++) = *(*(arr + i) + j); // copy values from two-dimensional array;
		}
	}

	void MenuChoiceFunc(int &choiceFunc);
	
	int choiceFunc = 0;
	MenuChoiceFunc(choiceFunc);
	
	void MenuFuncSort(int &choiceSort);
	
	int choiceSort = 0;
	MenuFuncSort(choiceSort);

	if (1 == choiceFunc)
		QuickSort(copyArr, (size - 1), choiceSort);
	if (2 == choiceFunc)
		BubbleSort(copyArr, (size - 1), choiceSort);
	PrintArr(copyArr, size);

	void MenuFuncCopy(int &choiceSort);
	
	MenuFuncCopy(choiceSort);
	if (1 == choiceSort)
	{
		CopyArr(arr, copyArr, row, column);
	}
	DynamicDelArr(copyArr);
}

void QuickSort(int *const copyArr, const int &lastIndx, const int &choiceSort)
{
	int i = 0, j = lastIndx, x = copyArr[lastIndx >> 1]; // bitwise right shift of 1 == copyArr[last / 2];
	
	do {
		if (1 == choiceSort)
		{
			while (*(copyArr + i) > x) i++;
			while (*(copyArr + j) < x) j--;
		}
		if (2 == choiceSort)
		{
			while (*(copyArr + i) < x) i++;
			while (*(copyArr + j) > x) j--;
		}

		if (i <= j) {
			SwapFunc(*(copyArr + i), *(copyArr + j));
			i++;
			j--;
		}
	} while (i <= j);
	if (lastIndx > i)
		QuickSort(copyArr + i, lastIndx - i, choiceSort);
	if (j > 0)
		QuickSort(copyArr, j, choiceSort);
}

void BubbleSort(int *const copyArr, const int &lastIndx, const int &choiceSort)
{
	bool CmpreFunc(const int &var1, const int &var2, const int &sort);
	
	int i, j;
	
	for (i = lastIndx; i >= 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (CmpreFunc(*(copyArr + j), *(copyArr + (j + 1)), choiceSort))
			{
				SwapFunc(*(copyArr + j), *(copyArr + (j + 1)));
			}
		}
	}
}

bool CmpreFunc(const int &var1, const int &var2, const int &choiceSort)
{
	if (2 == choiceSort)
	{
		return var1 > var2;
	}
	else
	if (1 == choiceSort)
	{
		return var1 < var2;
	}
	else
	{
		return 0;
	}
}

void MenuChoiceFunc(int &choiceFunc)
{
	cout << "\nFunc sort array:\n";
	
	string strExcptn;
	
	do
	{
		cout << "1. Use QuickSort Func;\n";
		cout << "2. Use BubbleSort Func;\n";
		cout << "Enter your choice: ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, choiceFunc);
		
		if (choiceFunc < 1 || choiceFunc > 2)
		{
			cout << "Incorrect input. Try again.\n";
		}
	} while (choiceFunc < 1 || choiceFunc > 2);
}

void MenuFuncSort(int &choiceSort)
{
	string strExcptn;
	
	do
	{
		cout << "1. Order sort: decrease;\n";
		cout << "2. Order sort: increase;\n";
		cout << "Enter your choice: ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, choiceSort);
		
		if (choiceSort < 1 || choiceSort > 2)
		{
			cout << "Incorrect input. Try again.\n";
		}
	} while (choiceSort < 1 || choiceSort > 2);
}

void MenuFuncCopy(int &choiceSort)
{
	cout << "\nFunc copy sorted array to original array?\n";
	
	string strExcptn;
	
	do
	{
		cout << "1. Copy.\n";
		cout << "2. Exit, without copy.\n";
		cout << "Enter your choice: ";
		getline(cin, strExcptn);
		ExceptionFunc(strExcptn, choiceSort);
		
		if (choiceSort < 1 || choiceSort > 2)
		{
			cout << "Incorrect input. Try again.\n";
		}
	} while (choiceSort < 1 || choiceSort > 2);
}
