#include <vector>
#include <unordered_map>

// %100 Performance & Task Score & Correctness
// Codility: In how many ways can you split a kingdom into two parts, so that the parts contain equal number of gold mines ?
int solution(int N, int M, std::vector<int>& X, std::vector<int>& Y) {
	// write your code in C++14 (g++ 6.2.0)

	if (X.size() % 2 != 0)
	{
		// there are odd number gold boroughs!
		return 0;
	}

	int res = 0;

	// store all column/row values by counting them only once
	// they will be used below when we are searching needed gold boroughs
	std::unordered_map<int, int> umapY, umapX;
	for (int i : Y)
	{
		++umapY[i];
	}

	for (int i : X)
	{
		++umapX[i];
	}

	// how many gold boroughs we are looking for
	// either half size of X or Y vector
	int neededGoldCount = X.size() / 2;

	// if vertical column (M) count is 1 then there is no need to check
	bool yConsistOneColumn = umapY[0] == static_cast<int>(Y.size());
	if (!yConsistOneColumn)
	{
		int temp = 0;
		for (auto i = 0; i < M; ++i)
		{
			temp += umapY[i];

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
	bool xConsistOneColumn = umapX[0] == static_cast<int>(X.size());
	if (!xConsistOneColumn)
	{
		int temp = 0;
		for (auto i = 0; i < N; ++i)
		{
			temp += umapX[i];

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