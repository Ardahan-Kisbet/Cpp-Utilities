#include "UtilityCls.h"


// Trim Operation
void UtilityCls::Trim(char* src, size_t length)
{
	size_t headIdx = 0;
	size_t tailIdx = 0;
	if (length > 0)
	{
		tailIdx = length - 1;
	}
	// Else condition is not needed. If length is not greater than zero than tailIdx should be kept as 0

	char temp[32] = {};

	if ((headIdx != tailIdx) && (length <= 32))
	{
		while (src[headIdx] == ' ')
		{
			++headIdx;
		}

		while (src[tailIdx] == ' ' && tailIdx > 0)
		{
			--tailIdx;
		}

		if (headIdx > tailIdx)
		{
			// Then all characters are whitespace
			src[0] = '\0';
		}
		else
		{
			for (size_t i = 0; i <= (tailIdx - headIdx); ++i)
			{
				temp[i] = src[headIdx + i];
			}
		}

		// Clear source string
		// ensures null terminating for the remaining unused places
		std::memset(src, 0, length);

		for (unsigned int i = 0; i <= (tailIdx - headIdx); ++i)
		{
			src[i] = temp[i];
		}

	}
	else if (length == 1)
	{
		if (src[0] == ' ')
		{
			std::memset(src, 0, length);
		}

	}
	// Else source string is empty or greater than 32 characters. Do not take any action
}