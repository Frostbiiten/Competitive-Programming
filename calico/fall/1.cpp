#include <ios>
#include <iostream>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int t, cases;
    std::cin >> cases;

    while (cases--)
    {
        std::cin >> t;
        t /= 10;

        if (t == 0)
        {
            std::cout << "haha good one\n";
        }
        else if (t >= 1 && t <= 17)
        {
            for (int i = 0; i < t; ++i)
            {
                std::cout << "berkeley";
            }
            std::cout << "time\n";
        }
        else
        {
            std::cout << "canceled\n";
        }
    }
}