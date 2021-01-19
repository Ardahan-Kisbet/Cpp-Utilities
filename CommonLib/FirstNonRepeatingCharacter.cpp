#include <unordered_map>

// Finding First Non-Repeating Character In Given String
char FirstNonRepeatingCharacter(const char* src, size_t length)
{
	// There is two seperate for loop for given source which leads to O(2N), hence O(N) Complexity

	char result = '_';

	// Using Key-Value Pair is definetly more efficent in constrast to using brute-force way by doing 2 loops
	std::unordered_map<char, int> uMap;

	for (size_t i = 0; i < length; ++i)
	{
		// unordered map O(1) lookup
		if (uMap[src[i]])
		{
			// if hash map has this key then increase count value
			++uMap[src[i]];
		}
		else
		{
			// add ne new pair to map
			uMap[src[i]] = 1;
		}
	}

	// Now our each character and count of them are ready
	// get first un-repeated one
	for (size_t i = 0; i < length; ++i)
	{
		if (uMap[src[i]] == 1)
		{
			result = src[i];
			// break at first occurence
			break;
		}
	}

	return result;
}