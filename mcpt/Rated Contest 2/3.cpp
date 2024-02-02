#include <iostream>
#include <cstdint>

int c[1000000];

// money saved by choosing pair that starts at index i
int saved[1000000 - 1];
int dp[1000000 - 1];

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n; uint64_t sum = 0;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> c[i];
        sum += c[i];
    }

    // sweep all pairs
    for (int i = 0; i < n - 1; ++i) saved[i] = std::min(c[i], c[i + 1]) / 2;
    
    dp[0] = saved[0];
    dp[1] = saved[1];
    for (int i = 2; i < n - 1; ++i) dp[i] = std::max(dp[i - 1], dp[i - 2] + saved[i]);
    std::cout << sum - std::max(dp[n - 2], dp[n - 3]);
    
    return 0;
}