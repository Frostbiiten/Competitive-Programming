#include <iostream>
#include <climits>
#include <vector>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n;
    std::cin >> n;
    
    char current;
    int last = 0;

    std::cin >> current;
    char prev = current;

    int least = INT_MAX;

    std::vector<int> blocks;
    blocks.reserve(300000);

    for (int i = 1; i < n; ++i)
    {
        std::cin >> current;

        if (current != prev)
        {
            if (prev == '1')
            {
                int v = i - last;
                blocks.push_back(i - last);

                if (last == 0)
                {
                    least = std::min(least, v - 1);
                }
                else
                {
                    least = std::min(least, v / 2);
                }
            }
            last = i;
        }

        prev = current;
    }

    if (prev == '1')
    {
        blocks.push_back(n - last);
        least = std::min(least, (n - last - 1));
    }

    if (least == INT_MAX)
    {
        std::cout << "0\n";
        return 0;
    }

    int min = INT_MAX;

    // attempt each daycount to minimize
    for (int dayC = 0; dayC <= least; ++dayC)
    {
        int localSum = 0;
        for (int i = 0; i < blocks.size(); ++i)
        {
            localSum += std::max(blocks[i] - 2 * dayC, 1);
        }

        min = std::min (min, localSum);
    }

    std::cout << min << '\n';
}