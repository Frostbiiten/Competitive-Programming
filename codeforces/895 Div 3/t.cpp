#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t;
    std::cin >> t;

    int a, b, c;
    for (int test = 0; test < t; ++test)
    {
        std::cin >> a >> b >> c;
        int div = c << 1;
        std::cout << (std::abs(a - b) + div - 1) / div << '\n';
    }

    return 0;
}