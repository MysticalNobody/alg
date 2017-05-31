#include "stdafx.h"
void selectionSort(int* input_array, int size_array) // сортировка выбором
{
	for (int repeat_counter = 0; repeat_counter < size_array; repeat_counter++)
	{
		int temp = input_array[0]; // временная переменная для хранения значения перестановки
		for (int element_counter = repeat_counter + 1; element_counter < size_array; element_counter++)
		{
			if (input_array[repeat_counter] > input_array[element_counter])
			{
				temp = input_array[repeat_counter];
				input_array[repeat_counter] = input_array[element_counter];
				input_array[element_counter] = temp;
			}
		}
	}
}