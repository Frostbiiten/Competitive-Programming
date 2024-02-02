#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    std::string s;
    std::cin >> s;

    bool t = isupper(s[0]);

    if (t)
    {
        for (int i = 1; i < s.size(); ++i)
        {
            if (isupper(s[i]))
            {
                t = false;
                break;
            }
        }
    }

    if (t)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
}