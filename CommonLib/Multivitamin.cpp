//codility
//Multivitamin Question
//Tas Score 52%
//Correctness 100%
//Performance 11%
//All big entries are failed in terms of time constraint
//Only small & medium array entries are passed in time
//
//Detected time complexity :
//O(N**2)

#include <algorithm>
#include <functional>
#include <unordered_map>
#include <utility>
#include <iostream>

// find maximum possible juices mixture in only one glass
int solution(std::vector<int>& juice, std::vector<int>& capacity) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_map<int, int> umapJuice;
    std::vector<std::pair<int, int>> diff;
    int index = 0;
    for (int i : juice)
    {
        ++umapJuice[i];
        diff.push_back(std::make_pair(index, capacity[index] - juice[index]));
        ++index;
    }

    int maxMix = 1;

    for (int i = diff.size() - 1; i >= 0; --i)
    {
        int currDiff = diff[i].second;
        int currIdx = diff[i].first;

        int currJuice = 1;
        int currMix = 1;
        int loading = 0;
        bool completed = false;
        while ((completed == false) && (loading <= currDiff) && currJuice <= currDiff)
        {
            int currLoading = 0;
            if (currJuice != juice[currIdx])
            {
                currLoading += umapJuice[currJuice] * currJuice;
            }
            else
            {
                if (umapJuice[currJuice] > 0)
                {
                    currLoading += (umapJuice[currJuice] - 1) * currJuice;
                }
                // Else: only itself exist on hash map
            }

            while ((loading + currLoading) > currDiff)
            {
                currLoading -= currJuice;
                completed = true;
            }

            currMix += currLoading / currJuice;
            loading += currLoading;

            // search for next juice to fill it up!
            ++currJuice;
        }

        maxMix = currMix > maxMix ? currMix : maxMix;
    }
    return maxMix;
}
