#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, in; 
    std::uint64_t sum;
    std::cin >> n;
    sum = n * (n + 1ull) >> 1;

    for (int i = 1; i < n; ++i)
    {
        std::cin >> in;
        sum -= in;
    }
    
    std::cout << sum;
}