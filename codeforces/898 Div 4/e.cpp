// not working
#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int t; char in;
    std::cin >> t;

    int n, x;
    while (t--)
    {
        std::cin >> n >> x;
        int a[n], maxH = -1;
    
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            maxH = std::max(a[i], maxH);
        }

        std::sort(a, a + n);

        int current = 0, est = 0, h = 0;
        while (current < n && est < x)
        {
            int diff = a[current] - h;
            if (diff > 0)
            {
                est += current * diff;
                h += diff;
            }

            ++current;
        }

        if (est < x) h += (x - est) / n;

        std::cout << h - 1 << '\n';
    }
}
