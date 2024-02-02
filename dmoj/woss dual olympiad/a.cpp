#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);

    int n, q;
    std::cin >> n >> q;

    int sand[n + 1];
    sand[0] = 0;

    int prev = 0;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> sand[i];
        sand[i] += prev;
        prev = sand[i];
    }

    // queries
    int a, b, c;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> a >> b >> c;

        switch (a)
        {
        case 1:
            sand[b - 1] += c;
            break;
        case 2:
            sand[b] -= c;
            break;
        case 3:
            std::cout << sand[c] - sand[b - 1] << '\n';
            break;
        }
    }
    
    return 0;
}