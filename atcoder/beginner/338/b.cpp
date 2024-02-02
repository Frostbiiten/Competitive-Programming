#include <iostream>

int freq[26];

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int bestInd = 26;
    int best = 0;
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        int ind = s[i] - 'a';
        ++freq[ind];
        if (freq[ind] >= best)
        {
            if (freq[ind] == best && ind >= bestInd) continue;
            bestInd = ind;
            best = freq[ind];
        }
    }

    std::cout << (char)('a' + bestInd);
}