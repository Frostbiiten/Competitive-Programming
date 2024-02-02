// http://www.usaco.org/index.php?page=viewproblem2&cpid=1060
// alternate solution

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;
    int p[n], sum[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        sum[i] = p[i];
    }

    // base
    int count = n;

    for (int width = 1; width < n; ++width)
    {
        for (int start = 0; start < n - width; ++start)
        {
            int rangeSum = sum[start] + p[start + width];

            for (int j = start; j <= start + width; ++j)
            {
                if (p[j] * (width + 1) == rangeSum)
                {
                    ++count;
                    break;
                }
            }

            sum[start] = rangeSum;
        }
    }

    std::cout << count << '\n';
    return 0;
}