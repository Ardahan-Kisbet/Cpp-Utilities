#include <string>

// Length of Last Word
int LengthOfLastWord(std::string s)
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