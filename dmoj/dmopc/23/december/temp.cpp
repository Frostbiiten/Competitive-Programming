#include <ios>
#include <iostream>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, k;
    std::cin >> n >> k;

    int nSqr = n * n;

    if (k > n || k == 0)
    {
        std::cout << "-1\n";
    }
    else
    {
        int kAdded = 0;
        int c = 1;

        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                if (row == col && kAdded + 1 < k)
                {
                    std::cout << nSqr - kAdded << ' ';
                    ++kAdded;
                    continue;
                }

                std::cout << c << ' ';
                ++c;
            }

            std::cout << '\n';
        }
    }

    return 0;
}