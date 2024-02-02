#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int x, y, diff;
    std::cin >> x >> y;

    diff = y - x;
    if (diff <= 2 && diff >= -3)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}
