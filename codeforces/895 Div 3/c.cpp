#include <iostream>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;

    int l, r;
    for (int test = 0; test < t; ++test)
    {
        std::cin >> l >> r;

        bool comp = false;
        for (int sum = l; sum <= r; ++sum)
        {
            for (int a = 2; a <= (l >> 1); ++a)
            {
                int b = sum - a;
            
                // mini sieve (?)
                for (int div = 2; div <= std::min(a, b); ++div)
                {
                    std::cout << div << '\n';
                    if (a % div == 0 && b % div == 0)
                    {
                        std::cout << a << ' ' << b << '\n';
                        comp = true;
                        break;
                    }
                }

                if (comp) break;
            }

            if (comp) break;
        }

        if (!comp) std::cout << "-1\n";
    }

    return 0;
}