#include <iostream>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, letters = 0; std::string s;
    std::cin >> s >> n;

    if (n > s.size())
    {
        std::cout << "impossible\n";
        return 0;
    }

    for (int i = 0; i < s.size(); ++i) letters |= 1 << (s[i] - 'a');
    std::cout << std::max(n - __builtin_popcount(letters), 0) << '\n';
}