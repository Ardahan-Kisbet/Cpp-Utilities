#include <string>
#include <unordered_map>

// Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(std::string s) {

	int previousMaxLength = 0;
	int currMaxLength = 0;

	std::unordered_map<char, int> umap;

	// starting to search from first character
	int startIndex = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		auto c = s[i];

		if (umap.find(c) == umap.end())
		{
			// first encounter
			umap[c] = 1;
			++currMaxLength;
		}
		else
		{
			// already exist
			// repeating character
			previousMaxLength = std::max(currMaxLength, previousMaxLength);

			// start loop again from near character of our previous started character
			i = startIndex;
			++startIndex;

			// reset hash map and counter for next longest substring search
			currMaxLength = 0;
			umap.clear();
		}
	}

	// last check for maximum one since substring may last till the end
	previousMaxLength = std::max(currMaxLength, previousMaxLength);

	return previousMaxLength;
}