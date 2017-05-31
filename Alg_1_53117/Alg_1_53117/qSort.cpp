#include "stdafx.h"
void qSort(int* array, int l, int r) // Быстрая сортировка
{
	int x = array[l + (r - l) / 2];
	int i = l;
	int j = r;
	int temp = 0;
	while (i <= j)
	{
		while (array[i] < x)
		{
			i++;
		}
		while (array[j] > x)
		{
			j--;
		}
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r)
		qSort(array, i, r);

	if (l < j)
		qSort(array, l, j);
}