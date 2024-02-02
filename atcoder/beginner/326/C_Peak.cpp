#include <algorithm>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    int gifts[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> gifts[i];
    }

    std::sort(gifts, gifts + n);

    int right = 0, sum = 0;
    for (int left = 0; left < n; ++left)
    {
        if (gifts[right] - gifts[left] < m)
        {
            sum = std::max(sum, right - left + 1);

            if (right < n - 1)
            {
                ++right;
                --left;
            }
        }
    }

    std::cout << sum << "\n";

    return 0;
}