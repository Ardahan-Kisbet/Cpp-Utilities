#include "SortCls.h"

// Bubble Sort Algorithm
void SortCls::BubbleSort(int* src, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		bool isSwapped = false;
		for (size_t j = 0; j < size - i - 1; ++j)
		{
			if (src[j] > src[j + 1])
			{
				int temp = src[j];
				src[j] = src[j + 1];
				src[j + 1] = temp;
				isSwapped = true;
			}
		}

		if (!isSwapped)
		{
			// Then source is already sorted
			break;
		}
	}
}

// Insertion Sort Algorithm
void SortCls::InsertionSort(int* src, size_t size)
{
	// loop index 1 to n
	for (size_t i = 1; i < size; i++)
	{
		int j = i;
		// swap current element till it find a place 
		// where it is no longer smaller than the element besides left of it.
		while (j > 0 && src[j] < src[j - 1])
		{
			int temp = src[j-1];
			src[j - 1] = src[j];
			src[j] = temp;
			--j;
		}		
	}
}
