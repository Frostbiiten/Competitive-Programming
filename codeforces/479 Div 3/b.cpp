// https://codeforces.com/contest/977/problem/B
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int len;
    std::string str;
    std::cin >> len >> str;

    int occ[26 * 26];
    std::memset(occ, 0, sizeof(occ));

    for (int i = 0; i < len - 1; ++i)
    {
        int ind0 = str[i] - 'A';
        int ind1 = str[i + 1] - 'A';
        ++occ[ind0 * 26 + ind1];
    }

    int greatest = -1, greatestInd = 0;

    for (int i = 0; i < 26 * 26; ++i)
    {
        if (occ[i] > greatest)
        {
            greatestInd = i;
            greatest = occ[i];
        }
    }

    char a = (greatestInd / 26);
    char b = (greatestInd - a * 26);
    std::cout << (char)(a + 'A') << (char)(b + 'A') << '\n';
    return 0;
}