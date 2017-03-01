#include <iostream>
using std::cout;
using std::cin;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"

void Var4(void)
{
	cout << "\nExercise. Variant 4 start.";
	int row = 0, column = 0;
	cout << "\n\nIMPORTANT NOTE: In this task, the rows must be equal\n\t\tto the columns for correct work.\n";
	int **arr = DynamicCrteIntArr(row, column);
	if (row != column)
	{
		DynamicDelArr(arr, row);
		cout << "Input incorrect data. Try again. Read the NOTE carefully.\n\n";
		cout << "Exercise. Variant 4 emergency end.\n";
		cout << "..................................................................\n\n";
		return;
	}

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);

	int i, j, indxArr = 0; // 1) start.
	const int rowElemArr = row; // const value for dynamic memory allocation without request;
	long double *prdctElemArr = DynamicCrteLDblArr(rowElemArr);
	for (i = 0; i < row; i++) // initialize dynamic array value: 1;
		*(prdctElemArr + i) = 1;
	bool itrtnFlag = 0, prdctFlag = 0;
	for (i = 0; i < row; )
	{
		for (j = 0; j < column; j++)
		{
			if (0 > *(*(arr + i) + j)) // if the item is a negative, move on to the next row;
			{
				itrtnFlag = 1;
				break;
			}
			if (prdctFlag) // condition when row is positive;
			{
				*(prdctElemArr + indxArr) *= *(*(arr + i) + j); // product elements from positive row;
				if (j >= (column - 1)) // when the last element is reached, perform:
				{
					indxArr++;
					prdctFlag = 0;
					itrtnFlag = 1;
				}
			}
		}
		if (!itrtnFlag) // if current row is positive, product them elements; 
		{
			prdctFlag = 1;
			cout << "Index of positive row: " << i << ";\n";
		}
		if (itrtnFlag) // the only option to go to the next row;
		{
			i++;
			itrtnFlag = 0;
		}
	}
	if (0 != indxArr)
		cout << "Summary info about product of elements in positive row(s):\n";
	else
		cout << "Positive row(s) not found.\n";
	PrintArr(prdctElemArr, indxArr);
	DynamicDelArr(prdctElemArr); // 1) end.

	const int size = (row * 2 - 2); // 2) start.
	int *mainDgnlSumArr = new int[size];
	indxArr = 0;
	for (i = 0; i < size; i++) // initialize dynamic array value: 0;
		*(mainDgnlSumArr + i) = 0;
	// uncomment line 78, 91, 93 for display work this cycle;
	//cout << "Summary info about sum of elements in diagonals of array:\n\n";
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (j == i)
			    continue;
			if (0 == i || 0 == j)
			{
				int a, b;
				for (a = i, b = j; a < row && b < column; a++, b++)
				{
					*(mainDgnlSumArr + indxArr) += *(*(arr + a) + b);
					//cout << "Element of diagonal: arr[" << a << "][" << b << "] = " << *(*(arr + a) + b) << ";\n";
				}
				//cout << "Sum of diagonal is: " << *(mainDgnlSumArr + indxArr) << ", indxArr: " << indxArr << ";\n\n";
				indxArr++;
			}
			else
				continue;
		}
	}
	j = *mainDgnlSumArr; // calc max sum;
	for (i = 0; i < size; i++)
	if (*(mainDgnlSumArr + i) > j)
		j = *(mainDgnlSumArr + i);
	cout << "Max sum of sums of elements in diagonals of array: " << j << ";\n";
	PrintArr(mainDgnlSumArr, size);
	DynamicDelArr(mainDgnlSumArr); // 2) end.

	DynamicDelArr(arr, row);
	cout << "Exercise. Variant 4 end.\n";
	cout << "..................................................................\n\n";
}