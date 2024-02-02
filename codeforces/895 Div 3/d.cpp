#include <iostream>
#include <numeric>

std::int64_t rangeSum(uint64_t a, uint64_t b)
{
    std::int64_t sumA = (a * (a - 1)) >> 1;
    std::int64_t sumB = (b * (b + 1)) >> 1;
    return sumB - sumA;
}

// not working on test case 3 (overflow?)

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t;
    std::cin >> t;

    int n, x, y;
    for (int test = 0; test < t; ++test)
    {
        std::cin >> n >> x >> y;

        std::uint64_t lcm = std::lcm(x, y);
        std::uint64_t both = n / lcm;
        std::uint64_t max = n / x - both;
        std::uint64_t min = n / y - both;

        // only min and max make a difference
        std::int64_t maxSum = rangeSum(n - max + 1, n);
        std::int64_t minSum = (min * (min + 1)) >> 1;
        std::cout << maxSum - minSum << '\n';
    }

    return 0;
}