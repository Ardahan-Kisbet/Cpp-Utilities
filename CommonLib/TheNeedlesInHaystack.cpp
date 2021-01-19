#include <string>

int TheNeedleInHaystack(std::string haystack, std::string needle)
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