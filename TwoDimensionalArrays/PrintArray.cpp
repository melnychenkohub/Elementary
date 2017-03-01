#include <iostream>
using std::cout;

void PrintArr(const float *const *const arr, const int &row, const int &column) 
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			cout << "arr[" << i << "][" << j << "]: " << *(*(arr + i) + j) << '\n';
		}
		cout << '\n';
	}
}

void PrintArr(const int *const *const arr, const int &row, const int &column) 
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			cout << "arr[" << i << "][" << j << "]: " << *(*(arr + i) + j) << '\n';
		}
		cout << '\n';
	}
}

void PrintArr(const long double *const arr, const int &size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << "arr[" << i << "]: " << *(arr + i) << '\n';
	}
	cout << '\n';
}

void PrintArr(const float *const arr, const int &size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << "arr[" << i << "]: " << *(arr + i) << '\n';
	}
	cout << '\n';
}

void PrintArr(const int *const arr, const int &size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << "arr[" << i << "]: " << *(arr + i) << '\n';
	}
	cout << '\n';
}

void PrintArr(const float *const *const arr, const int &row, const int &column, const bool &show)
{
	int i, j;
	if (show) // if show true, show uncompressed print; else compressed print;
	{
		cout << "Columns:";
		for (j = 0; j < column; j++)
		{
			cout << "\t[" << j << "]";
		}
		cout << "\n\n";
		for (i = 0; i < row; i++)
		{
			cout << "Row: [" << i << "]";
			for (j = 0; j < column; j++)
			{
				cout << "\t" << *(*(arr + i) + j);
			}
			cout << "\n\n";
		}
	}
	else
	{
		cout << "Columns:";
		for (j = 0; j < column; j++)
		{
			cout.width(5);
			cout << "[" << j << "]";
		}
		cout << '\n';
		for (i = 0; i < row; i++)
		{
			cout << "Row: [" << i << "]";
			for (j = 0; j < column; j++)
			{
				cout.width(7);
				cout << *(*(arr + i) + j);
			}
			cout << '\n';
		}
	}
}
void PrintArr(const int *const *const arr, const int &row, const int &column, const bool &show)
{
	int i, j;
	if (show) // if show true, show uncompressed print; else compressed print;
	{
		cout << "Columns:";
		for (j = 0; j < column; j++)
		{
			cout << "\t[" << j << "]";
		}
		cout << "\n\n";
		for (i = 0; i < row; i++)
		{
			cout << "Row: [" << i << "]";
			for (j = 0; j < column; j++)
			{
				cout << "\t" << *(*(arr + i) + j);
			}
			cout << "\n\n";
		}
	}
	else
	{
		cout << "Columns:";
		for (j = 0; j < column; j++)
		{
			cout.width(2);
			cout << "[" << j << "]";
		}
		cout << '\n';
		for (i = 0; i < row; i++)
		{
			cout << "Row: [" << i << "]";
			for (j = 0; j < column; j++)
			{
				cout.width(4);
				cout << *(*(arr + i) + j);
			}
			cout << '\n';
		}
	}
}