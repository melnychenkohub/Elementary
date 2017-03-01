#include <iostream>
using std::cout;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"
#include "SwapFunc.h"

void Var8(void)
{
	cout << "\nExercise. Variant 8 start.";
	int row = 0, column = 0;
	int **arr = DynamicCrteIntArr(row, column);

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);

	int i, j, clmnSumChrct1 = 0, clmnSumChrct2 = 0; // 1) start. gnome sort.
	for (j = 0; j < (column - 1);)
	{
		for (i = 1; i < row; i += 2)
		{
			if (0 > *(*(arr + i) + j))
			{
				clmnSumChrct1 += abs(*(*(arr + i) + j));
			}
			if (0 > *(*(arr + i) + (j + 1)))
			{
				clmnSumChrct2 += abs(*(*(arr + i) + (j + 1)));
			}
		}
		if (clmnSumChrct1 < clmnSumChrct2)
		{
		    int a, b = j;
			for (a = 0; a < row; a++)
			{
				SwapFunc(*(*(arr + a) + b), *(*(arr + a) + (b + 1)));
			}
			if (j > 0)
			{
				j--;
			}
		}
		else
		{
			j++;
		}
		//cout << "clmnSumChrct1: " << clmnSumChrct1 << ";\n"; // displayed sort work;
		//cout << "clmnSumChrct2: " << clmnSumChrct2 << ";\n"; // displayed sort work;
		clmnSumChrct1 = 0;
		clmnSumChrct2 = 0;
	}
	cout << "\nColumns are sorted in descending order, according to the task:\n";
	PrintArr(arr, row, column, show); // 1) end.

	const int clmnElemArr = column; // 2) start. // const value for dynamic memory allocation without request;
	int indxArr = 0, *sumElemArr = DynamicCrteIntArr(clmnElemArr);
	for (i = 0; i < column; i++) // initialize dynamic array value: 0;
		*(sumElemArr + i) = 0;
	bool itrtnFlag = 0, sumFlag = 0;
	for (j = 0; j < column;)
	{
		for (i = 0; i < row; i++)
		{
			if (!itrtnFlag && 0 > *(*(arr + i) + j)) // if the item is a negative, calc sum of elem of this column;
			{
				itrtnFlag = 1;
				break;
			}
			if (sumFlag) // condition when column is negative;
			{
				*(sumElemArr + indxArr) += *(*(arr + i) + j); // sum elements from negative column;
				if (i >= (row - 1)) // when the last element is reached, perform:
				{
					indxArr++; 
					sumFlag = 0;
					itrtnFlag = 0;
				}
			}
		}
		if (itrtnFlag) // if current column is negative, sum them elements; 
		{
			sumFlag = 1;
			cout << "Index of negative column: " << j << ";\n";
		}
		if (!itrtnFlag) // the only option to go to the next column;
		{
			j++;
		}
	}
	if (0 != indxArr)
		cout << "Summary info about sum of elements in negative column(s):\n";
	else
		cout << "Negative column(s) not found.\n";
	PrintArr(sumElemArr, indxArr);
	DynamicDelArr(sumElemArr); // 1) end.

	DynamicDelArr(arr, row);
	cout << "Exercise. Variant 8 end.\n";
	cout << "..................................................................\n\n";
}
