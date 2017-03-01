#include <iostream>
using std::cout;

void DynamicDelArr(float **arr, const int &row)
{
	int i;
	for (i = 0; i < row; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
	cout << "Dynamic allocated memory for float **array delete.\n\n";
}

void DynamicDelArr(int **arr, const int &row)
{
	int i;
	for (i = 0; i < row; i++)
	{
		delete[] * (arr + i);
	}
	delete[] arr;
	cout << "Dynamic allocated memory for int **array delete.\n\n";
}

void DynamicDelArr(long double *arr)
{
	delete[] arr;
	cout << "Dynamic allocated memory for float *array delete.\n\n";
}

void DynamicDelArr(float *arr)
{
	delete[] arr;
	cout << "Dynamic allocated memory for float *array delete.\n\n";
}

void DynamicDelArr(int *arr)
{
	delete[] arr;
	cout << "Dynamic allocated memory for int *array delete.\n\n";
}