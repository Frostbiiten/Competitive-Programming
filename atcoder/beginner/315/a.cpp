#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') continue;
        std::cout << s[i];
    }

    return 0;
}