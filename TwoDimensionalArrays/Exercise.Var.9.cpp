#include <iostream>
using std::cout;
using std::cin;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"

void Var9(void)
{
	cout << "\nExercise. Variant 9 start.";
	int row = 0, column = 0;
	cout << "\n\nIMPORTANT NOTE: In this task, the rows must be equal\n\t\tto the columns for correct work.";
	int **arr = DynamicCrteIntArr(row, column);
	if (row != column)
	{
		DynamicDelArr(arr, row);
		cout << "Input incorrect data. Try again. Read the NOTE carefully.\n\n";
		cout << "Exercise. Variant 9 emergency end.\n";
		cout << "..................................................................\n\n";
		return;
	}

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);

	if (1 == row)
	{
		cout << "\nAverage array:\n";
		PrintArr(arr, row, column, show);
		DynamicDelArr(arr, row);
		cout << "Exercise. Variant 9 simple end.\n";
		cout << "..................................................................\n\n";
		return;
	}

	int rowCpy = 0, columnCpy = 0;
	cout << "\nIMPORTANT NOTE: In this task, the rows and columns must be equal\n\t\tprevious rows and columns for correct work.";
	int **arrCpy = DynamicCrteIntArr(rowCpy, columnCpy);
	if (rowCpy != row || columnCpy != columnCpy)
	{
		DynamicDelArr(arr, row);
		DynamicDelArr(arrCpy, rowCpy);
		cout << "Input incorrect data. Try again. Read the NOTE carefully.\n\n";
		cout << "Exercise. Variant 9 emergency end.\n";
		cout << "..................................................................\n\n";
		return;
	}

	int i, j; // 1) start. brute)
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (0 == i) // the upper row of array;
			{
				if (0 == j)
				{
					*(*(arrCpy + i) + j) = (*(*(arr + (i + 1)) + j) + *(*(arr + i) + (j + 1))) / 2;
				}
				else
				if ((column - 1) == j)
				{
					*(*(arrCpy + i) + j) = (*(*(arr + (i + 1)) + j) + *(*(arr + i) + (j - 1))) / 2;
				}
				else
				{
					*(*(arrCpy + i) + j) = (*(*(arr + (i + 1)) + j) + *(*(arr + i) + (j + 1)) + *(*(arr + i) + (j - 1))) / 3;
				}
			}
			else
			if ((column - 1) == j) // the right column of array;
			{
				if ((row - 1) == i)
				{
					*(*(arrCpy + i) + j) = (*(*(arr + (i - 1)) + j) + *(*(arr + i) + (j - 1))) / 2;
				}
				else
				{
					*(*(arrCpy + i) + j) = (*(*(arr + (i + 1)) + j) + *(*(arr + (i - 1)) + j) + *(*(arr + i) + (j - 1))) / 3;
				}
			}
			else
			if ((row - 1) == i) // the lower row of array;
			{
				if (0 == j)
				{
					*(*(arrCpy + i) + j) = (*(*(arr + (i - 1)) + j) + *(*(arr + i) + (j + 1))) / 2;
				}
				else
				{
					*(*(arrCpy + i) + j) = (*(*(arr + (i - 1)) + j) + *(*(arr + i) + (j + 1)) + *(*(arr + i) + (j - 1))) / 3;
				}
			}
			else
			if (0 == j) // the left column of array;
			{
				*(*(arrCpy + i) + j) = (*(*(arr + (i - 1)) + j) + *(*(arr + (i + 1)) + j) + *(*(arr + i) + (j + 1))) / 3;
			}
			else
			if (i > 0 && i < (row - 1) && j > 0 && j < (column - 1)) // center of array;
			{
				*(*(arrCpy + i) + j) = (*(*(arr + (i + 1)) + j) + *(*(arr + (i - 1)) + j) + *(*(arr + i) + (j + 1)) + *(*(arr + i) + (j - 1))) / 4;
			}
		}
	}
	cout << "\nAverage array:\n";
	PrintArr(arrCpy, row, column, show); // 1) end.

	DynamicDelArr(arr, row);
	DynamicDelArr(arrCpy, rowCpy);
	cout << "Exercise. Variant 9 end.\n";
	cout << "..................................................................\n\n";
}