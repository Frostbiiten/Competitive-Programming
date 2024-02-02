#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    bool o = n & 1;
    for (int row = 0; row < n; ++row)
    {
        int rMod = row % 4;
        bool r = (rMod == 1 || rMod == 2);
        for (int col = 0; col < n; ++col)
        {
            if (o && row <= 5 && col <= 5)
            {
                std::cout << ((std::abs(2 - row) + std::abs(2 - col)) <= 1) << ' ';
            }
            else
            {
                int cMod = col % 4;
                bool c = (cMod == 1 || cMod == 2);
                std::cout << (r && c) << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}