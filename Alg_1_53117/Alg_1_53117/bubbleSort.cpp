#include "stdafx.h"
void bubbleSort(int* arrayPtr, int length_array) // Сортировка пузырьком
{
	int temp = 0;
	for (int i = 0; i < length_array - 1; i++) {
		if (arrayPtr[i] > arrayPtr[i + 1]) {
			temp = arrayPtr[i];
			arrayPtr[i] = arrayPtr[i + 1];
			arrayPtr[i + 1] = temp;
			i = -1;
		}
	}
}
