#include "stdafx.h"
int* countSort(int* inputArray, int sizeArray) // Сортировка подсчётом
{
	//Создание второго массива
	int* countArr = new int[sizeArray];
	int countArrSize = 0;
	for (int i = 0; i < sizeArray; i++) {
		bool isUnique = true;
		for (int j = 0; j < countArrSize; j++) {
			if (inputArray[i] == countArr[j]){
				isUnique = false;
				break;
			}
		}
		if (isUnique){
			countArr[countArrSize] = 0; 
			countArrSize += 1;
		}
	}
	//Сортировка
	for (int i = 0; i < sizeArray; i++) {
		countArr[inputArray[i] - 1] += 1;
	}
	for (int i = 1; i < countArrSize; i++) {
		countArr[i] += countArr[i - 1];
	}
	int* outputArr = new int[sizeArray];
	for (int i = sizeArray; i > 0; i--) {
		outputArr[countArr[inputArray[i - 1] - 1] - 1] = inputArray[i];
		countArr[inputArray[i - 1]] -= 1;
	}
	return outputArr;
}