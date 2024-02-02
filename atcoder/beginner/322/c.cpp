#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, m, last = 0, current;
    std::cin >> n >> m;
    int a[m];

    for (int i = 0; i < m; ++i)
    {
        std::cin >> current;
        a[i] = current - last - 1;
        last = current;
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = a[i]; j >= 0; --j)
        {
            std::cout << j << '\n';
        }
    }

    return 0;
}