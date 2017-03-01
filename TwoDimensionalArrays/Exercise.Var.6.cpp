#include <iostream>
using std::cout;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"
#include "SaddlePointOfArray.h"

void Var6(void)
{
	cout << "\nExercise. Variant 6 start.";
	int row = 0, column = 0;
	int **arr = DynamicCrteIntArr(row, column);

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);

	int i, j; // 1) start.
	const int rowElemArr = row; // const value for dynamic memory allocation without request;
	int indxArr = 0, *sumElemArr = DynamicCrteIntArr(rowElemArr);
	for (i = 0; i < row; i++) // initialize dynamic array value: 0;
		*(sumElemArr + i) = 0;
	bool itrtnFlag = 0, sumFlag = 0;
	for (i = 0; i < row;)
	{
		for (j = 0; j < column; j++)
		{
			if (!itrtnFlag && 0 > *(*(arr + i) + j)) // if the all items is a positive, move on to the next row;
			{
				itrtnFlag = 1;
				break;
			}
			if (sumFlag) // condition when row is negative;
			{
				*(sumElemArr + indxArr) += *(*(arr + i) + j); // sum elements from negative row;
				if (j >= (column - 1)) // when the last element is reached, perform:
				{
					indxArr++;
					sumFlag = 0;
					itrtnFlag = 0;
				}
			}
		}
		if (itrtnFlag) // if current row is negative, sum them elements; 
		{
			sumFlag = 1;
			cout << "Index of negative row: " << i << ";\n";
		}
		if (!itrtnFlag) // the only option to go to the next row;
		{
			i++;
		}
	}
	if (0 != indxArr)
		cout << "Summary info about sum of elements in negative row(s):\n";
	else
		cout << "Negative row(s) not found.\n";
	PrintArr(sumElemArr, indxArr);
	DynamicDelArr(sumElemArr); // 1) end.

	indxArr = 0; // 2) start. indxArr - counter;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (SaddlePntArr(arr, row, column, i, j))
			{
				indxArr++;
				cout << "Saddle point of array found: arr[" << i << "][" << j << "] = " << *(*(arr + i) + j) << ";\n";
			}
		}
	}
	cout << '\n';
	if (0 == indxArr)
		cout << "Sadlle point(s) not found in this array.\n\n"; // 2) end.

	DynamicDelArr(arr, row);
	cout << "Exercise. Variant 6 end.\n";
	cout << "..................................................................\n\n";
}