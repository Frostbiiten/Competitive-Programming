// TLE :(
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n;
    std::cin >> n;

    int p[n];
    double p2[n];

    double max = 1;
    int maxStart = 0, maxLen = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        p2[i] = p[i];
        if (p[i] > max)
        {
            max = p2[i];
            maxStart = i;
            maxLen = 0;
        }
    }

    double prevMax = 0;
    for (int i = 1; i < n; ++i)
    {
        double p2Max = 0;
        for (int j = 0; j < n - i; ++j)
        {
            p2[j] = ((p2[j] * i) * p[j + i]) / (i + 1);
            p2Max = std::max(p2Max, p2[j]);

            if (p2[j] > max)
            {
                max = p2[j];
                maxStart = j;
                maxLen = i;
            }

            //std::cout << p2[j] << ' ';
        }
        //std::cout << "\n";

        if (p2Max < prevMax)
        {
            break;
        }

        prevMax = p2Max;
    }

    ++maxStart;
    std::cout << maxStart << ' ' << (maxStart + maxLen) << '\n';
}