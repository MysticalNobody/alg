#include "stdafx.h"
void countSort(int* input_array, int size_array) // Сортировка подсчётом
{
	int* countArr = new int[size_array];
	for (int i = 0; i < size_array; i++) {
		countArr[i] = 0;
	}

	for (int i = 0; i < size_array; i++)
	{
		countArr[input_array[i]]++;
	}

	int outputindex = 0;
	for (int j = 0; j < 1000; j++)
	{
		while (countArr[j]--)
			input_array[outputindex++] = j;
	}

}