// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
// lucky because road length is tiny (<100), see other apporach for more sparse roads
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	int road[100];

	int len, lim, current = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> len >> lim;
		std::fill_n(road + current, len, lim);
		current += len;
	}

	int speed, violation = 0;
	current = 0;

	for (int i = 0; i < m; ++i)
	{
		std::cin >> len >> speed;
		for (int j = 0; j < len; ++j)
		{
			violation = std::max(violation, speed - road[current + j]);
		}

		current += len;
	}

	std::cout << violation << '\n';

	return 0;
}
