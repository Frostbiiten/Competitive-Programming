#include <iostream>
#include <stdint.h>
#include <string>
#include <cstdint>

int main()
{
    std::string s;
    uint64_t sum = 0;

    while (std::getline(std::cin, s) )
    {
        int first, second;

        // first
        for (int i = 0; i < s.size(); ++i)
        {
            int val = s[i] - '0';
            if (val >= 0 && val <= 9)
            {
                first = val;
                break;
            }
        }

        // end
        for (int i = s.size() - 1; i >= 0; --i)
        {
            int val = s[i] - '0';
            if (val >= 0 && val <= 9)
            {
                second = val;
                break;
            }
        }

        sum += first * 10 + second;
    }

    std::cout << sum << '\n';

    return 0;
}