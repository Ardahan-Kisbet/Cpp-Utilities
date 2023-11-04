#include <queue>
#include <vector>

using namespace std;

class Interval
{
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;

	}
};


/**
* @param schedule: a list schedule of employees
* @return: Return a list of finite intervals
*/
vector<Interval> employeeFreeTime(vector<vector<int>>& schedule) {
	// Write your code here
	vector<Interval> result;

	auto comp = [](Interval a, Interval b) { return a.start > b.start; };
	std::priority_queue<Interval, vector<Interval>, decltype(comp)> pq(comp);
	for (int i = 0; i < schedule.size(); i++)
	{
		for (int j = 0; j < schedule[i].size() - 1; j += 2)
		{
			pq.push(Interval(schedule[i][j], schedule[i][j + 1]));
		}
	}

	auto curr = pq.top();
	pq.pop();
	while (!pq.empty())
	{
		if (curr.end > pq.top().start)
		{
			curr.end = pq.top().end;
			pq.pop();
		}
		else
		{
			result.push_back(Interval(curr.end, pq.top().start));
			curr = pq.top();
			pq.pop();
		}
	}

	return result;

}