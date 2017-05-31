#include "stdafx.h"
void insertSort(int* input_array, int size_array) // Сортировка вставками
{
	int temp = 0;
	for (int i = 1; i < size_array; i++)
		for (int j = i; j > 0 && input_array[j - 1] > input_array[j]; j--)
		{
			temp = input_array[j];
			input_array[j] = input_array[j - 1];
			input_array[j - 1] = temp;
		}
}