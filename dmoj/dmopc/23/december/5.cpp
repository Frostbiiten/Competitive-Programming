#include <iostream>
#include <algorithm>
#include <cstdint>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;

    int a[n];
    int b[n];

    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a, a + n);

    for (int i = 0; i < n; ++i) std::cin >> b[i];
    std::sort(b, b + n);
    
    uint64_t total = 0;
    for (int i = 0; i < n; ++i) total += std::abs(a[i] - b[i]);

    std::cout << total << '\n';
    return 0;
}