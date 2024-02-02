#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, in, min = 1001;
    std::cin >> n;

    bool s[1000];
    memset(s, 0, sizeof(s));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        --in;
        min = std::min(min, in);
        s[in] = true;
    }
    
    for (int i = 0; i < n; ++i)
    {
        if (!s[min + i])
        {
            std::cout << min + i + 1 << '\n';
            return 0;
        }
    }
}