#include <iostream>
#include <vector>

typedef std::pair<int, int> handshake;

int main()
{
	// time [1, 250]
	// cows [2, 100]

    int n, interactions;
    std::cin >> n >> interactions;

    int state[n];

    char in;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        state[i] = (in == '1') - 1;
    }

	std::vector<handshake> arr[250];

	int t, x, y, latest = -1;
	for (int i = 0; i < interactions; ++i)
	{
		std::cin >> t >> x >> y;
		--t; --x; --y;
		latest = std::max(t, latest);

		arr[t].push_back({x, y});
	}

	for (int time = latest; time >= 0; --time)
	{

	}

    return 0;
}
