// Alg_1_53117.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

void fillArray(int* array, int size_array)  // функция для заполнения массива
{
	for (int i = 0; i < size_array; i++)
	{
		if (i < 10) {
			array[i] = 10 - i;
		}
		else {
			array[i] = rand() % 100 + 10; 
		}
	}
}

int main()
{
	std::cout << "Input array size: ";
	int size_array; // длинна массива
	std::cin >> size_array;
	int *input_array = new int[size_array];
#pragma region qSort
	fillArray(input_array, size_array);
	unsigned int start_time = clock();
	qSort(input_array, 0, size_array - 1);
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	std::cout << "Quick sort";
	std::cout << "Array:  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << input_array[i] << "  ";
	}
	std::cout << "\n" << "time:  " << search_time << "  " << "mills" << std::endl;
#pragma endregion
	std::cout << "\n";
#pragma region countSort
	fillArray(input_array, size_array);
	start_time = clock();
	countSort(input_array, size_array);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	std::cout << "Count sort";
	std::cout << "Array:  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << input_array[i] << "  ";
	}
	std::cout << "\n" << "time:  " << search_time << "  " << "mills" << std::endl;
#pragma endregion
	std::cout << "\n";
#pragma region insertSort
	fillArray(input_array, size_array);
	start_time = clock();
	insertSort(input_array, size_array);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	std::cout << "Insert sort";
	std::cout << "Array:  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << input_array[i] << "  ";
	}
	std::cout << "\n" << "time:  " << search_time << "  " << "mills" << std::endl;
#pragma endregion
	std::cout << "\n";
#pragma region selectionSort
	fillArray(input_array, size_array);
	start_time = clock();
	selectionSort(input_array, size_array);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	std::cout << "Selection sort";
	std::cout << "Array:  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << input_array[i] << "  ";
	}
	std::cout << "\n" << "time:  " << search_time << "  " << "mills" << std::endl;
#pragma endregion
	std::cout << "\n";
#pragma region shellSort
	fillArray(input_array, size_array);
	start_time = clock();
	shellSort(input_array, size_array);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	std::cout << "Shell sort";
	std::cout << "Array:  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << input_array[i] << "  ";
	}
	std::cout << "\n" << "time:  " << search_time << "  " << "mills" << std::endl;
#pragma endregion
	std::cout << "\n";
#pragma region bubbleSort
	fillArray(input_array, size_array);
	start_time = clock();
	bubbleSort(input_array, size_array);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	std::cout << "Bubble sort";
	std::cout << "Array:  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << input_array[i] << "  ";
	}
	std::cout << "\n" << "time:  " << search_time << "  " << "mills" << std::endl;
#pragma endregion

	system("pause");
	return 0;
}


