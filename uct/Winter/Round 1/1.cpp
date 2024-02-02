#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    std::string s;
    std::cin >> s;

    for (int i = 5; i < s.size() + 5; ++i)
    {
        char c = s[i % s.size()];
        bool lower = (c >= 'a' && c <= 'z');

        if (lower) c -= 'a';
        else c -= 'A';

        c = (c - 4) % 26;
        if (c < 0) c += 26;

        if (lower) c += 'a';
        else c += 'A';

        std::cout << c;
    }

    return 0;
}