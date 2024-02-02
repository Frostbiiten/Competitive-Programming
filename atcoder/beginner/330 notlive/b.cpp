#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, l, r;
    std::cin >> n >> l >> r;

    int current;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> current;
        std::cout << std::min(std::max(current, l), r) << ' ';
    }
    std::cout << '\n';

    return 0;
}