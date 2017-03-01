#include <iostream>
using std::cout;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"
#include "SwapFunc.h"

void Var2(void)
{
	cout << "\nExercise. Variant 2 start.";
	int row = 0, column = 0;
	int **arr = DynamicCrteIntArr(row, column);

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);

	int i, j, countColmn = 0; // 1) start.
	bool flag = 0;
	for (j = 0; j < column; j++)
	{
		for (i = 0; i < row; i++)
		{
			if (0 == *(*(arr + i) + j))
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			countColmn++;
		}
		if (flag)
		{
			flag = 0;
		}
	}
	cout << "Amount column without 0: " << countColmn << " of " << column << ".\n"; // 1) end.

	int rowSumChrct1 = 0, rowSumChrct2 = 0; // 2) start. gnome sort.
	for (i = 0; i < (row - 1); )
	{
		for (j = 0; j < column; j += 2)
		{
			if (*(*(arr + i) + j) > 0)
			{
				rowSumChrct1 += *(*(arr + i) + j);
			}
			if (*(*(arr + (i + 1)) + j) > 0)
			{
				rowSumChrct2 += *(*(arr + (i + 1)) + j);
			}
		}
		if (rowSumChrct1 < rowSumChrct2)
		{
			SwapFunc(arr, i);
			if (i > 0)
			{
				i--;
			}
		}
		else
		{
			i++;
		}
		rowSumChrct1 = 0;
		rowSumChrct2 = 0;
	}
	cout << "\nRows are sorted in ascending order, according to the task:\n";
	PrintArr(arr, row, column, show); // 2) end.

    DynamicDelArr(arr, row);
	cout << "Exercise. Variant 2 end.\n";
	cout << "..................................................................\n\n";
}