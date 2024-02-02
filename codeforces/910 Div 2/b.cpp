#include <iostream>

int a[10000];

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t;
    std::cin >> t;

    while(t--)
    {
        int n, count = 0;
        std::cin >> n;
        for (int i = n -  1; i >= 0; --i) std::cin >> a[i];

        // array reversed while reading in, everything on 'left' side of reversed array must be larger

        int s = a[0];
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > s)
            {
                a[i] = a[i] >> 1;
                s = a[i];
                ++count;
                --i;
            }
        }

        std::cout << count << '\n';
    }
}