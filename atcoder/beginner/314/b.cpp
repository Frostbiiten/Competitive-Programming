#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.tie(0); std::cout.tie(0); std::ios_base::sync_with_stdio(0);

    int n, a;
    std::cin >> n;

    int count[n];
    std::uint64_t masks[n], x;
    memset(masks, 0, sizeof(masks));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> count[i];
        for  (int j = 0; j < count[i]; ++j)
        {
            std::cin >> a;
            masks[i] |= 1ull << a;
        }
    }

    std::cin >> x;
    std::uint64_t bit = 1ull << x;
    std::vector<int> correct;
    int correctMin = 38;

    for (int i = 0; i < n; ++i)
    {
        if (count[i] <= correctMin && (bit & masks[i]) == bit)
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
    for (auto ans : correct) std::cout << ans + 1 << ' ';
    std::cout << '\n';

    return 0;
}