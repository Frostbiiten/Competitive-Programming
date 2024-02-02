// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
#include <iostream>

int main()
{
	// n segments, m speed limit (1-100)
	int n, m;
	std::cin >> n >> m;

	std::pair<int, int> road[n];

	// road segments
	int current = 0;
	for (int i = 0; i < n; ++i)
	{
		// get road length and speed limit
		std::cin >> road[i].first >> road[i].second;
		road[i].first += current;
		current = road[i].first;
	}

	// journey segments
	int len, speed, violation = 0;
	int prev, prevI = 0, currentI = 0;
	current = 0;
	for (int i = 0; i < m; ++i)
	{
		// get road length and speed limit
		int prev = current;
		prevI = currentI;
		std::cin >> len >> speed;
		current += len;

		// iterate current & currentI up to correct road
		while (current <= road[i].first)
		{
			++currentI;
			current = road[currentI].first;
		}


		for (int j = prevI; j <= currentI; ++j)
		{
			violation = std::max(violation, speed - road[j].second);
		}
	}

	std::cout << violation << '\n';
}
