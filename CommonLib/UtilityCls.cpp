#include "UtilityCls.h"
#include <cstring> 
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iostream>
#include <unordered_set>

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

// Finding First Non-Repeating Character In Given String
// There is two seperate for loop for given source which leads to O(2N), hence O(N) Complexity
char UtilityCls::FirstNonRepeatingCharacter(const char* src, size_t length)
{
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

// Length of Last Word
int UtilityCls::lengthOfLastWord(std::string s)
{
	int counter = 0;
	bool spaceEncountered = false;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if ((s[i] == ' ') && (spaceEncountered == false))
		{
			// Set space encountered flag to true
			spaceEncountered = true;
		}
		else if ((s[i] != ' ') && (spaceEncountered == false))
		{
			// Then start/continue counting
			++counter;
		}
		else if ((s[i] != ' ') && (spaceEncountered == true))
		{
			// then we encountered with new word
			// reset counter
			// new word's first letter encountered
			counter = 1;
			// set space encountered flag to false
			spaceEncountered = false;
		}
		// Else: consecutive white spaces, ignore it
	}

	return counter;
}

// Find Max Depth of a Binary Tree (LinkedList)
int UtilityCls::MaximumDepthOfBinaryTree(TreeNode* root)
{
	// We can traverse binary tree preorder while calculating the levels recursively

	// null check
	if (root == nullptr)
		return 0;

	// this node itself count as 1
	int count = 1;

	// check depths of left and right childs then get the maximum among them
	count += std::max(MaximumDepthOfBinaryTree(root->left), MaximumDepthOfBinaryTree(root->right));

	//max(maxDepth(root->left), maxDepth(root->right))

	return count;
}

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
bool UtilityCls::ValidParantheses(std::string s)
{
	// init a true
	bool result = true;

	std::unordered_map<char, char> lookupTable;
	lookupTable[')'] = '(';
	lookupTable['}'] = '{';
	lookupTable[']'] = '[';
	lookupTable['('] = ')';
	lookupTable['{'] = '}';
	lookupTable['['] = ']';

	std::unordered_set<char> closedSet = { ')', '}',']' };

	// we need to keep stack which represents open parentheses
	std::stack<char> openList;

	for (auto c : s)
	{
		if (closedSet.find(c) != closedSet.end())
		{
			if (openList.empty())
			{
				// then first occurence is closing parenthesis
				return false;
			}
			else
			{
				// then we encountered with a closing paranthesis. So that there should be a
				// corresponding opening one in our stack
				if (openList.top() != lookupTable[c])
				{
					// there is no corresponding opening for this closing parenthesis
					result = false;
				}
				else
				{
					// then we have a match - remove matching pair
					openList.pop();
				}
			}
		}
		else
		{
			// it is an opening parenthesis, store it
			openList.push(c);
		}
	}

	// at the end our stack should be empty
	if (!openList.empty())
	{
		result = false;
	}
	return result;
}

int UtilityCls::strStr(std::string haystack, std::string needle)
{
	if (needle.empty())
	{
		return 0;
	}
	else
	{
		size_t found = haystack.find(needle);
		if (found != std::string::npos)
		{
			return found;
		}
		else
		{
			return -1;
		}
	}
}

// Codility: In how many ways can you split a kingdom into two parts, so that the parts contain equal number of gold mines ?
int DividingTheKingdom(int N, int M, std::vector<int>& X, std::vector<int>& Y) {
	// write your code in C++14 (g++ 6.2.0)
	
	// 78% Task Score 100% correctness %50 Performance

	if (X.size() % 2 != 0)
	{
		// there are odd number gold boroughs!
		return 0;
	}

	int res = 0;

	// how many gold boroughs we are looking for
	// either half size of X or Y vector
	int neededGoldCount = X.size() / 2;

	// if vertical column (M) count is 1 then there is no need to check
	bool yConsistOneColumn = std::count(Y.begin(), Y.end(), 0) == static_cast<int>(Y.size());
	if (!yConsistOneColumn)
	{
		int temp = 0;
		for (auto i = 0; i < M; ++i)
		{
			temp += std::count(Y.begin(), Y.end(), i);

			if (temp == neededGoldCount)
			{
				++res;
			}
			else if (temp > neededGoldCount)
			{
				// then there is no possibility to divide fairly again
				break;
			}
			// Else: keep going until we reach to end of N  
		}
	}

	// if horizontal column (N) count is 1 then there is no need to check
	bool xConsistOneColumn = std::count(X.begin(), X.end(), 0) == static_cast<int>(X.size());
	if (!xConsistOneColumn)
	{
		int temp = 0;
		for (auto i = 0; i < N; ++i)
		{
			temp += std::count(X.begin(), X.end(), i);

			if (temp == neededGoldCount)
			{
				++res;
			}
			else if (temp > neededGoldCount)
			{
				// then there is no possibility to divide fairly again
				break;
			}
			// Else: keep going until we reach to end of M                 
		}
	}

	return res;
}