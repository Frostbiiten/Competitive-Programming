#include <iostream>
#include <stdint.h>
#include <string>
#include <cstdint>
#include <vector>

int main()
{
    std::string s;
    uint64_t sum = 0;

    std::vector<std::pair<int, std::string>> nums = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}
    };

    while (std::getline(std::cin, s) )
    {
        int first, second;

        // first
        auto beginCopy = nums;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                int ind = 0;
                for (auto num: beginCopy)
                {
                    if (j < num.second.size() && i + j < s.size() && s[j] != s[i + j])
                    {
                        beginCopy.erase(beginCopy.begin() + ind);
                        if (beginCopy.size() == 1) break;
                        --ind;
                    }
                    ++ind;
                }
            }
        }

        first = beginCopy[0].first;

        // second
        auto endCopy = nums;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = 5; j >= 0; --j)
            {
                int ind = 0;
                for (auto num: beginCopy)
                {
                    if (j < num.second.size() && i + j < s.size() && s[j] != s[i + j])
                    {
                        beginCopy.erase(beginCopy.begin() + ind);
                        if (beginCopy.size() == 1) break;
                        --ind;
                    }
                    ++ind;
                }
            }
        }

        second = endCopy[0].first;

        std::cout << first * 10 + second << '\n';
        sum += first * 10 + second;
    }

    std::cout << sum << '\n';

    return 0;
}