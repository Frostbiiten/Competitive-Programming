#include <ios>
#include <cstring>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, targetB, bCount = 0;

        std::string s;
        std::cin >> n >> targetB >> s;

        //totals
        for (int i = 0; i < n; ++i)
        {
            bool a = (s[i] == 'A');
            bCount += !a;
        }

        if (bCount == targetB)
        {
            std::cout << "0\n";
            continue;
        }

        std::cout << "1\n";
        int deltaB = targetB - bCount;
        int partitionA = 0;

        for (int range = 0; range < n; ++range)
        {
            // how many b's in partition
            partitionA += (s[range] == 'A');
            int partitionB = range + 1 - partitionA;

            if (deltaB == partitionA)
            {
                std::cout << range + 1 << " B\n";
                break;
            }
            else if (-deltaB == partitionB)
            {
                std::cout << range + 1 << " A\n";
                break;
            }
        }
    }

    return 0;
}