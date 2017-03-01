void SwapFunc(float &var1, float &var2)
{
	float temp = var1;
	var1 = var2;
	var2 = temp;
}

void SwapFunc(int &var1, int &var2)
{
	int temp = var1;
	var1 = var2;
	var2 = temp;
}

void SwapFunc(float **const arr, const int &i)
{
	float *temp = *(arr + i);
	*(arr + i) = *(arr + (i + 1));
	*(arr + (i + 1)) = temp;
}

void SwapFunc(int **const arr, const int &i)
{
	int *temp = *(arr + i);
	*(arr + i) = *(arr + (i + 1));
	*(arr + (i + 1)) = temp;
}