#include <ios>
#include <iostream>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n; 
    std::string s;
    bool pass = false;

    std::cin >> n >> s;
    char prev = s[0];

    for (int i = 1; i < n; ++i)
    {
        char cur = s[i];
        if ((cur == 'a' || cur == 'b') && (prev == 'a' || prev == 'b') && cur != prev)
        {
            std::cout << "Yes\n";
            pass = true;
            break;
        }
        prev = cur;
    }

    if (!pass) std::cout << "No\n";

    return 0;
}