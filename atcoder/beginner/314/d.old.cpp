#include <iostream>
#include <cstring>

int main()
{
    std::cin.tie(0); std::cout.tie(0); std::ios_base::sync_with_stdio(0);

    int n, q;
    std::string s;
    std::cin >> n >> s >> q;

    bool lower = true, deviates[n];
    for (int i = 0; i < n; ++i) deviates[i] = islower(s[i]);

    int t, x; char c;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> t >> x >> c;
        if (t == 1)
        {
            --x;
            deviates[x] = lower != islower(c);
            s[x] = c;
        }
        else
        {
            lower = !(t - 2);
            memset(deviates, 0, sizeof(deviates));
        }
    }

    for (int i = 0; i < n; ++i)
    {
        char current = s[i];
        current = lower == deviates[i] ? toupper(current) : tolower(current);
        std::cout << current;
    }
    std::cout << '\n';

    return 0;
}