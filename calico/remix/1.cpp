#include <ios>
#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    while (t--)
    {
        int n, b, w, d;
        std::cin >> n >> b >> w >> d;
        int hfull = (n + 1) * b;
        int hcur, hhole = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> hcur;
            hhole += hcur;
        }

        hfull += hhole;

        std::cout << (hfull * (w + 2 * b) - hhole * w) * d << '\n';
    }

    return 0;
}