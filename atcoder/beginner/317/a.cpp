#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, h, x, best = 999, ind, in;
    std::cin >> n >> h >> x;
    ind = n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        if (in < best && h + in >= x)
        {
            ind = i + 1;
            best = in;
        }
    }

    std::cout << ind;
}