#include <iostream>
#include <algorithm>
#include <climits>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, min = INT_MAX, max = INT_MIN;
    std::cin >> n;
    int a[n];

    std::uint64_t total = 0, days;
    for (int i = 0; i < n; ++i)
    {
       std::cin >> a[i];
       min = std::min(min, a[i]);
       max = std::max(max, a[i]);
       total += a[i];
    }

    days = total;
    std::sort(a, a + n);

    days -= min * n;
    for (int i = 1; i < n; ++i)
    {
        int diff = (n - i) * (a[i] - a[i - 1]);
        days -= diff - 1;
    }

    std::cout << days << '\n';
    return 0;
}