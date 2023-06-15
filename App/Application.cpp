#include <stdlib.h>
#include <iostream>
#include "SortCls.h"
#include "UtilityCls.h"
#include <unordered_map>
#include "IsPalindrome.cpp"
#include "iterator.h"

int main()
{
	// TRIM EXAMPLE
	std::cout << "String Trim Operation" << std::endl;
	char cArr[9] = "  TEST  ";
	char* cPtr = &cArr[0];
	std::cout << "Before Trim: " << cPtr << std::endl;
	UtilityCls util;
	util.Trim(cPtr, sizeof(cArr) - 1);
	std::cout << "After Trim: " << cPtr << std::endl;

	// BUBBLE SORT EXAMPLE
	std::cout << std::endl << std::endl;
	std::cout << "Buble Sort Operation" << std::endl;
	int arr[5] = { 3,1,8,6,7 };
	std::cout << "Before Sort: ";
	for (auto i : arr)
	{
		std::cout << " " << i << " ";
	}
	SortCls sort;
	sort.BubbleSort(&arr[0], 5);
	std::cout << std::endl << "After Sort: ";
	for (auto i : arr)
	{
		std::cout << " " << i << " ";
	}

	//custom array with iterator
	std::cout << std::endl << std::endl;
	std::cout << std::endl << "custom array with iterator: ";
	Util::myArray<int, 10> myArr = { 1, 2, 3, 4, 5, 0, -1, -2, 2, 10 };

	for (auto i : myArr)
	{
		std::cout << i << std::endl;
	}

    std::cin.get();
}


