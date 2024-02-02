#include <iostream>
#include <cstdint>
int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t, a, b, n, current;
    std::cin >> t;
    while (t--)
    {
        std::cin >> a >> b >> n;
        std::uint64_t sum = b;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> current;
            sum += std::min(current, a - 1);
        }

        std::cout << sum << '\n';
    }

    return 0;
}