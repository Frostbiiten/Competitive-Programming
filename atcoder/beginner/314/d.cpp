#include <iostream>
#include <cstring>

int main()
{
    std::cin.tie(0); std::cout.tie(0); std::ios_base::sync_with_stdio(0);

    int n, q; std::string s;
    std::cin >> n >> s >> q;

    int updated[n];
    memset(updated, 0, sizeof(updated));

    int globalUpdate = -1;
    int lower = true;

    int t, x; char c;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> t >> x >> c;
        if (t == 1)
        {
            --x;
            s[x] = c;
            updated[x] = i;
        }
        else
        {
            lower = t == 2;
            globalUpdate = i;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        char current = s[i];
        if (updated[i] < globalUpdate) current = lower ? tolower(current) : toupper(current);
        std::cout << current;
    }
    std::cout << '\n';

    return 0;
}