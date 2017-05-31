#include "stdafx.h"
void shellSort(int* input_array, int size_array) // Сортировка Шелла
{
	int i, j, step;
	int tmp;
	for (step = size_array / 2; step > 0; step /= 2)
		for (i = step; i < size_array; i++)
		{
			tmp = input_array[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < input_array[j - step])
					input_array[j] = input_array[j - step];
				else
					break;
			}
			input_array[j] = tmp;
		}
}