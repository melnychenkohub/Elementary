#include <iostream>
using std::cout;
#include "DynamicCreateArray.h"
#include "FillArray.h"
#include "PrintArray.h"
#include "DynamicDeleteArray.h"

void Var3(void)
{
	cout << "\nExercise. Variant 3 start.";
	int row = 0, column = 0;
	int **arr = DynamicCrteIntArr(row, column);

	FillArr(arr, row, column);
	const bool show = 0; // if show true, show uncompressed print; else compressed print;
	PrintArr(arr, row, column, show);

	int i, j, countColmn = 0; // 1) start.
	for (j = 0; j < column; j++)
	{
		for (i = 0; i < row; i++)
		{
			if (0 == *(*(arr + i) + j))
			{
				countColmn++;
				break;
			}
		}
	}
	cout << "Amount column with 0: " << countColmn << " of " << column << ".\n"; // 1) end.

	int a, k, count = 0, arrSeriaIndx = 0, memIndx = 0; // 2) start.
	// NOTE: The greater the array, the greater the value to be entered to sizeInfoArr.
	const int sizeInfoArr = row * column; // const value for dynamic memory allocation without request;
	int *const maxSeriaInRowArr = DynamicCrteIntArr(sizeInfoArr);
	int *const rowIndxWithMaxSeriaArr = DynamicCrteIntArr(sizeInfoArr);
	int *const numArr = DynamicCrteIntArr(sizeInfoArr);
	int *const memIndxArr = new int[column];
	bool flag = 0;
	for (a = 0; a < row; a++)
	{
		for (i = 0; i < column; i++)
		{
			for (k = 0; k < memIndx; k++) // block search duplicate values of indexes;
			{
				if (i == *(memIndxArr + k))
				{
					flag = 1;
					break;
				}
			}
			if (flag) // block skip iteration, if found duplicate values of indexes;
			{
				flag = 0;
				continue;
			}
			for (j = 0; j < column; j++)
			{
				if (*(*(arr + a) + i) == *(*(arr + a) + j)) // important, all info, counter block;
				{
					count++;
					flag = 1;
				}
				if (count > 1 && flag) // block writes duplicate values of indexes;
				{
					*(memIndxArr + memIndx++) = j;
					flag = 0;
				}
			}
			if (count > 1) // block writes all info to appropriate arrays; 
			{              
				if (sizeInfoArr > arrSeriaIndx)
				{
					*(numArr + arrSeriaIndx) = *(*(arr + a) + i);
					*(maxSeriaInRowArr + arrSeriaIndx) = count;
					*(rowIndxWithMaxSeriaArr + arrSeriaIndx) = a;
					arrSeriaIndx++;
				}
			}
			count = 0;
		}
		memIndx = 0;
	}
	if (arrSeriaIndx > 0)
	{
		cout << "Info on all series of equal numbers in a row(s) in this array:\n";
		for (i = 0; i < arrSeriaIndx; i++)
		{
			cout << "Seria of " << *(maxSeriaInRowArr + i) << " equal numbers: " << *(numArr + i) << ", in this array, are in " << *(rowIndxWithMaxSeriaArr + i) << " row.\n";
		}
	}
	else
		cout << "A series of identical numbers in any row(s) is not found in the array.\n"; // 2) end.

	DynamicDelArr(arr, row);
	DynamicDelArr(maxSeriaInRowArr);
	DynamicDelArr(rowIndxWithMaxSeriaArr);
	DynamicDelArr(numArr);
	DynamicDelArr(memIndxArr);
	cout << "Exercise. Variant 3 end.\n";
	cout << "..................................................................\n\n";
}