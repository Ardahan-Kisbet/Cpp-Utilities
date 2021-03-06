#include <stdlib.h>
#include <iostream>
#include <conio.h>

#include "SortCls.h"
#include "UtilityCls.h"
#include <unordered_map>
#include "IsPalindrome.cpp"
#include <ProtocolCls.h>
using namespace std;

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
    
	ProtocolFactory factory;
	unique_ptr<IProtocol> protocol = factory.CreateProtocol(ProtocolType::Protocol_UDP);
	std::cout<< std::endl<<static_cast<int>(protocol->GetType()) <<std::endl;

    std::cin.get();
}


