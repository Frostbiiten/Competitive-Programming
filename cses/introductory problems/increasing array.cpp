#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    long long n, last, cur, sum = 0;

    std::cin >> n;
    std::cin >> last;

    for (int i = 1; i < n; ++i)
    {
        std::cin >> cur;

        long long diff = std::max(0ll, last - cur);;
        sum += diff;
        last = cur + diff;
    }

    std::cout << sum << '\n';
    return 0;
}