// FOROGT 0 (sob), solved a few minutes after end of contest
#include <cstdint>
#include <ios>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int total = 0;
    std::uint64_t diff = 1, current = 0;

    int len;
    std::string n;
    std::cin >> len >> n;
    std::multiset<char> orig_set;
    int orig_sum = 0;

    for (int i = 0; i < n.size(); ++i)
    {
        orig_set.insert(n[i]);
        orig_sum += n[i] - '0';
    }

    if (orig_sum == 0)
    {
        std::cout << "1\n";
        return 0;
    }

    std::string least{};
    for (auto digit : orig_set) least += digit;
    std::string greatest = least;

    // min bound
    std::int64_t base = std::sqrt(std::stoull(least)) - 1;
    current = base * base;
    diff = 1ull + (base << 1);

    // max bound
    std::reverse(greatest.begin(), greatest.end());
    auto max = std::stoull(greatest);

    while (current <= max)
    {
        current += diff;
        diff += 2;

        std::multiset<char> cloneset{orig_set};
        int cloneSum = orig_sum;
        bool valid = true;

        std::string cur_str = std::to_string(current);
        for (int i = 0; i < cur_str.size(); ++i)
        {
            auto f = cloneset.find(cur_str[i]);
            if (f != cloneset.end())
            {
                cloneset.erase(f);
                cloneSum -= cur_str[i] - '0';
            }
            else
            {
                valid = false;
                break;
            }
        }

        total += valid && (!cloneSum);
    }

    std::cout << total << '\n';

    return 0;
}