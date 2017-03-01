void CopyArr(float **const arr, const float *const copyArr, const int &row, const int &column)
{
	int i, j, indx = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			*(*(arr + i) + j) = *(copyArr + indx++);
		}
	}
}

void CopyArr(int **const arr, const int *const copyArr, const int &row, const int &column)
{
	int i, j, indx = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			*(*(arr + i) + j) = *(copyArr + indx++);
		}
	}
}
