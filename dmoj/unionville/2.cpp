#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::cin >> n;
    if (n == 2)
    {
        std::cout << "1\n";
    return 0;
    }
    std::cout << (n - 1) + 2 * (1 + (n - 3) / 4);
    return 0;
}