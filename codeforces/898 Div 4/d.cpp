#include <iostream>
#include <cstring>
#include <iomanip>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int t; char in;
    std::cin >> t;

    int n, k, sum, last;
    while (t--)
    {
        last = -1;
        sum = 0;
        std::cin >> n >> k;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> in;
            if (in == 'B' && (last < 0 || (i - last) >= k))
            {
                last = i;
                ++sum;
            }
        }

        std::cout << sum << '\n';
    }
}