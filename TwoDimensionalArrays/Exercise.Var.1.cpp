#include <iostream>
using std::cout;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"

void Var1(void)
{
	cout << "\nExercise. Variant 1 start.";
	int row = 0, column = 0;
	int **arr = DynamicCrteIntArr(row, column);

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);
	
	int i, j, countRow = 0; // 1) start.
	bool flag = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (0 == *(*(arr + i) + j))
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			countRow++;
		}
		if (flag)
		{
			flag = 0;
		}
	}
	cout << "Amount row without 0: " << countRow << " of " << row << ".\n"; // 1) end.

	int a, b, count = 0, maxNum = -100; // 2) start.
	flag = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < column; b++)
		{
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < column; j++)
				{
					if (*(*(arr + a) + b) == *(*(arr + i) + j))
						count++;
					if (count > 1)
						break;
				}
				if (count > 1)
					break;
			}
			if (count > 1)
			{
				if (*(*(arr + a) + b) > maxNum)
					maxNum = *(*(arr + a) + b);
				flag = 1;
			}
			count = 0;
		}
	}
	if (flag)
	    cout << "Max equal numbers in this array is: " << maxNum << ".\n";
	if (!flag)
		cout << "Equal numbers in this array not found.\n";  // 2) end.

	DynamicDelArr(arr, row);
	cout << "Exercise. Variant 1 end.\n";
	cout << "..................................................................\n\n";
}