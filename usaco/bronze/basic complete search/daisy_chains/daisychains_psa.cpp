// http://www.usaco.org/index.php?page=viewproblem2&cpid=1060
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;
    int p[n], psa[n + 1];
    psa[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        psa[i + 1] = psa[i] + p[i];
    }

    int count = n;
    int rangePetals[1000];

    for (int start = 0; start < n; ++start)
    {
        for (int end = start + 1; end < n; ++end)
        {
            if (end == start + 1)
            {
                memset(rangePetals, 0, sizeof(rangePetals));
                for (int i = start; i <= end; ++i) ++rangePetals[p[i]];
            }
            else
            {
                ++rangePetals[p[end]];
            }

            int sum = psa[end + 1] - psa[start];
            int windowSize = (end - start + 1);
            if (sum % windowSize == 0 && rangePetals[sum / windowSize]) ++count;
        }
    }

    std::cout << count << '\n';
    return 0;
}