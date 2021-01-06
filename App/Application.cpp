#include <stdlib.h>
#include <iostream>
#include <conio.h>

#include "SortCls.h"
#include "UtilityCls.h"
#include <unordered_map>

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

	// First Non Repeating Character
	char cPtr2[] = "xaaabbccdedfeffg";
	char firtsNonRepeatingChar = util.FirstNonRepeatingCharacter(cPtr2, sizeof(cPtr2) - 1);

	// unoredered map using pair
	std::unordered_map<char, int> uMap;
	auto success = uMap.insert(std::pair<char, int>(cPtr2[0], 1));
	for (std::unordered_map<char, int>::iterator iter = uMap.begin(); iter != uMap.end(); ++iter)
	{
		std::cout << std::endl << (*iter).first << "  --> " << (*iter).second << std::endl;
	}
	// success.first->first; key char
	// success.first->second; value int

	// set Project --> Properties --> C/C++ --> Command Line --> Additional Options to /Zc:__cplusplus
	// Then select Project --> Properties --> C/C++ --> Language --> C++ Language Standards 
	//std::cout << "__cplusplus --> " << __cplusplus << std::endl;

	_getch();
}