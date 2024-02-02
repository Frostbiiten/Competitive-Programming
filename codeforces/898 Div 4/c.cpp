#include <iostream>
#include <iomanip>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int t; char in;
    std::cin >> t;

    while (t--)
    {
        int sum = 0;
        for (int y = 0; y < 10; ++y)
        {
            int rY = y > 4 ? 9 - y : y;
            for (int x = 0; x < 10; ++x)
            {
                std::cin >> in;
                if (in == 'X')
                {
                    int rX = x > 4 ? 9 - x : x;
                    sum += 5 - std::max(std::abs(rX - 4), std::abs(rY - 4));
                }
            }
        }
        std::cout << sum << '\n';
    }

    return 0;
}