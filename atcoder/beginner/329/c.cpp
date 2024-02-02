#include <ios>
#include <iostream>

int freq[26];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, total = 0, size = 1;
    std::string s;
    std::cin >> n >> s;

    char prev = 99, c;
    for (int i = 0; i < n; ++i)
    {
        c = s[i] - 'a';
        if (c == prev) ++size;
        else size = 1;

        freq[c] = std::max(freq[c], size);
        prev = c;
    }

    for (int i = 0; i < 26; ++i) total += freq[i];
    std::cout << total << '\n';

    return 0;
}