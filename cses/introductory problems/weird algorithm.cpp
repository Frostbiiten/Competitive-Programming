#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    std::uint64_t n;
    std::cin >> n;
    std::cout << n;

    while (n != 1)
    {
        if (n & 1) n = n * 3 + 1;
        else n >>= 1;
        std::cout << ' ' << n;
    }
}