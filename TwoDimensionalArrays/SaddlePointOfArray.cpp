bool SaddlePntArr(const float *const *const arr, const int &row, const int &column, const int &i, const int &j)
{
	int a = 0, b = 0, max = *(*(arr + a) + j), min = *(*(arr + i) + b), maxIndx = 0, minIndx = 0;
	for (a = 1; a < row; a++)
	{
		if (*(*(arr + a) + j) >= max)
		{
			if (*(*(arr + a) + j) == max && i == maxIndx)
				continue;

			max = *(*(arr + a) + j);
			maxIndx = a;
		}
	}
	if (maxIndx == i)
	{
		for (b = 1; b < column; b++)
		{
			if (min >= *(*(arr + i) + b))
			{
				if (*(*(arr + i) + b) == min && j == minIndx)
					continue;

				min = *(*(arr + i) + b);
				minIndx = b;
			}
		}
		if (minIndx == j)
			return 1;
		else
			return 0;
	}
	else
		return 0;

}
bool SaddlePntArr(const int *const *const arr, const int &row, const int &column, const int &i, const int &j)
{
	int a = 0, b = 0, max = *(*(arr + a) + j), min = *(*(arr + i) + b), maxIndx = 0, minIndx = 0;
	for (a = 1; a < row; a++)
	{
		if (*(*(arr + a) + j) >= max)
		{
			if (*(*(arr + a) + j) == max && i == maxIndx)
				continue;

			max = *(*(arr + a) + j);
			maxIndx = a;
		}
	}
	if (maxIndx == i)
	{
		for (b = 1; b < column; b++)
		{
			if (min >= *(*(arr + i) + b))
			{
				if (*(*(arr + i) + b) == min && j == minIndx)
					continue;

				min = *(*(arr + i) + b);
				minIndx = b;
			}
		}
		if (minIndx == j)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}