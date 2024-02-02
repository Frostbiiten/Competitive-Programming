#include <ios>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::cin >> n;

    while (true)
    {
        if (__builtin_popcount(n) == 1)
        {
            std::cout << "Yes\n";
            return 0;
        }
        else
        {
            int next = n / 3;
            if (next * 3 != n)
            {
                std::cout << "No\n";
                return 0;
            }
            n = next;
        }
    }
}