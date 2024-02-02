// https://codeforces.com/contest/977/problem/A
#include <string_view>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int k, in, lastChar;
    std::cin >> in >> k;
    std::string n = std::to_string(in);
    lastChar = n.size() - 1;

    while (k > 0)
    {
        int lastDigit = n[lastChar] - '0';
        int diff = std::min(lastDigit, k);
        lastDigit -= diff;
        k -= diff;
        n[lastChar] = lastDigit + '0';

        if (!k) break;
        else
        {
            --lastChar;
            --k;
        }
    }

    std::cout << std::string_view(n.data(), lastChar + 1) << '\n';
    return 0;
}