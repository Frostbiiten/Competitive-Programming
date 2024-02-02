#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <climits>

int main()
{
    std::cin.tie(0); std::cout.tie(0); std::ios_base::sync_with_stdio(0);
    int n, bet;
    std::cin >> n;

    std::uint64_t bets[n], x; int count[n];
    std::memset(bets, 0, sizeof(bets));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> count[i];
        for (int j = 0; j < count[i]; ++j)
        {
            std::cin >> bet;
            bets[i] |= 1ull << bet;
        }
    }

    std::cin >> x;

    std::uint64_t xMask = 1ull << x;
    std::vector<int> correct;
    int correctMin = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (count[i] <= correctMin && (xMask == (xMask & bets[i])))
        {
            if (count[i] < correctMin)
            {
                correct.clear();
                correctMin = count[i];
            }
            correct.push_back(i);
        }
    }

    std::sort(correct.begin(), correct.end());
    std::cout << correct.size() << '\n';
    for (auto a : correct) std::cout << (a + 1) << ' ';
    std::cout << '\n';

    return 0;
}