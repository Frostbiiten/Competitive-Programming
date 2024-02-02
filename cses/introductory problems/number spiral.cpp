#include <cstdint>
#include <iostream>
 
int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    int64_t t, x, y;
    std::cin >> t;
 
    while (t--)
    {
        std::cin >> y >> x;
        --x; --y;
 
        if (x < y) std::swap(x, y);
        
        // x * (x + 1) + 1 gets diagonal
        // the rest is the offset from it
        int64_t ans = x * (x + 1) + 1 + (2 * (x & 1) - 1) * (y - x);
        std::cout << ans << '\n';
    }
 
    return 0;
}