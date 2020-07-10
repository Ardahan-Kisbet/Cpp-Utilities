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
