#include <iostream>
using std::cout;
using std::cin;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"
#include "SortArray.h"

void Var5(void)
{
	cout << "\nExercise. Variant 5 start.";
	int row = 0, column = 0;
	cout << "\n\nIMPORTANT NOTE: In this task, the rows must be equal\n\t\tto the columns for correct work.\n";
	int **arr = DynamicCrteIntArr(row, column);
	if (row != column)
	{
		DynamicDelArr(arr, row);
		cout << "Input incorrect data. Try again. Read the NOTE carefully.\n\n";
		cout << "Exercise. Variant 5 emergency end.\n";
		cout << "..................................................................\n\n";
		return;
	}

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);

	int i, j; // 1) start.
	const int rowElemArr = row; // const value for dynamic memory allocation without request;
	int indxArr = 0, *sumElemArr = DynamicCrteIntArr(rowElemArr);
	for (i = 0; i < row; i++) // initialize dynamic array value: 0;
		*(sumElemArr + i) = 0;
	bool itrtnFlag = 0, sumFlag = 0;
	for (j = 0; j < column;)
	{
		for (i = 0; i < row; i++)
		{
			if (0 > *(*(arr + i) + j)) // if the item is a negative, move on to the next column;
			{
				itrtnFlag = 1;
				break;
			}
			if (sumFlag) // condition when column is positive;
			{
				*(sumElemArr + indxArr) += *(*(arr + i) + j); // sum elements from positive column;
				if (i >= (row - 1)) // when the last element is reached, perform:
				{
					indxArr++;
					sumFlag = 0;
					itrtnFlag = 1;
				}
			}
		}
		if (!itrtnFlag) // if current column is positive, sum them elements; 
		{
			sumFlag = 1;
			cout << "Index of positive column: " << j << ";\n";
		}
		if (itrtnFlag) // the only option to go to the next column;
		{
			j++;
			itrtnFlag = 0;
		}
	}
	if (0 != indxArr)
		cout << "Summary info about sum of elements in positive column(s):\n";
	else
		cout << "Positive column(s) not found.\n";
	PrintArr(sumElemArr, indxArr);
	DynamicDelArr(sumElemArr); // 1) end.

	const int size = (row * 2 - 2); // 2) start.
	int *scndrDgnlSumArr = new int[size];
	indxArr = 0;
	for (i = 0; i < size; i++) // initialize dynamic array value: 0;
		*(scndrDgnlSumArr + i) = 0;
	// uncomment line 79, 93, 94 for display work this cycle;
	//cout << "Summary info about sum of modulo elements in diagonals of array:\n\n";
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if ((i + j) == (row - 1))
				continue;
			else
			{
				if ((i + j) > (row - 1))
					indxArr = i + j - 1;
				else
				    indxArr = i + j;
				*(scndrDgnlSumArr + indxArr) += abs(*(*(arr + i) + j));
				//cout << "Element of diagonal: " << indxArr << ", arr[" << i << "][" << j << "] = " << *(*(arr + i) + j) << ";\n";
				//cout << "Sum of diagonal is: " << *(scndrDgnlSumArr + indxArr) << ";\n\n";
			}
		}
	}
	j = *scndrDgnlSumArr; // calc min sum;
	for (i = 0; i < size; i++)
	if (*(scndrDgnlSumArr + i) < j)
		j = *(scndrDgnlSumArr + i);
	cout << "Min sum of sums of modulo elements in diagonals of array: " << j << ";\n";
	PrintArr(scndrDgnlSumArr, size);
	DynamicDelArr(scndrDgnlSumArr); // 2) end.

	SortArr(arr, row, column);
	PrintArr(arr, row, column, show);

	DynamicDelArr(arr, row);
	cout << "Exercise. Variant 5 end.\n";
	cout << "..................................................................\n\n";
}