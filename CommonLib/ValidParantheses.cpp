#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>

// Leetcode: Valid Parantheses
bool ValidParantheses(std::string s)
{
	// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

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