#include <iostream>
#include <algorithm>

typedef std::pair<int, int> p;

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, c = 0, odd = 0, even = 0;
    std::cin >> n;
    int order[n];
    int o[n];
    int e[n];
    p a[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i].first;
        a[i].second = i + 1;
        if (a[i].first & 1)
        {
            o[odd] = i;
            ++odd;
        }
        else
        {
            e[even] = i;
            ++even;
        }
    }

    int p = 0;
    for (int i = 0; i < 1 && i < odd; ++i)
    {
        order[p] = o[i];
        ++p;
    }

    for (int i = 0; i < even; ++i)
    {
        order[p] = e[i];
        ++p;
    }

    for (int i = 1; i < odd; ++i)
    {
        order[p] = o[i];
        ++p;
    }

    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        c += (a[order[i]].first - (pos & 1)) / 2;
        pos += a[order[i]].first;
    }

    std::cout << c << '\n';
    for (int i = 0; i < n; ++i) std::cout << a[order[i]].second << ' ';
    std::cout << '\n';
}