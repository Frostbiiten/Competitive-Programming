#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int test;
    std::cin >> test;
    
    while (test--)
    {
        int n, m;
        std::string s, t;
        std::cin >> n >> m >> s >> t;

        bool tgood = true;
        char tsign = t[0];

        // check if t is good* and has same ends
        for (int i = 1; i < m; ++i)
        {
            if (t[i - 1] == t[i])
            {
                tgood = false;
                break;
            }
        }

        tgood = tgood && t[0] == t[m - 1];
        bool good = true;

        // check if s needs fixing
        for (int i = 1; i < n; ++i)
        {
            if (s[i - 1] == s[i])
            {
                if (!tgood || (s[i] == tsign))
                {
                    good = false;
                    break;
                }
            }
        }

        if (good)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
