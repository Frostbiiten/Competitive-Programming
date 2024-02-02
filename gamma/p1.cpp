#include <iostream>
#include <stdint.h>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n; char c;
    std::cin >> n;

    int64_t b[n];
    int64_t art = 0, music = 0;
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c;
        bool m = c == 'M';
        music += m;
        art += !m;
        b[i] = m;
    }
    
    uint64_t product1 = music * art;

    int currentMusic = 0;
    int64_t min = INT64_MAX;
    for (int div = 0; div < n; ++div)
    {
        currentMusic += b[div];
        min = std::min(min, std::abs(int64_t(product1 - ((art * currentMusic) + (music * (div + 1 - currentMusic))))));
    }

    std::cout << min;
    
    return 0;
}