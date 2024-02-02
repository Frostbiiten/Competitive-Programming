#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int tests;
    std::cin >> tests;

    std::vector<int> instructions;
    instructions.reserve(301);

    while (tests--)
    {
        int n;
        std::string s;
        std::cin >> n >> s;

        if (n & 1)
        {
            std::cout << "-1\n";
        }
        else
        {
            instructions.clear();
            bool good = true;

            for (int i = 0; i < s.size() / 2; ++i)
            {
                // check if mirrored
                if (s[i] == s[s.size() - i - 1])
                {
                    if (s[i] == '0')
                    {
                        int ind = s.size() - i;
                        s.insert(ind, "01");
                        instructions.push_back(ind);
                    }
                    else
                    {
                        s.insert(i, "01");
                        instructions.push_back(i);
                    }
                }

                if (instructions.size() > 300)
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                std::cout << instructions.size() << '\n';
                for (auto instruction : instructions) std::cout << instruction << ' ';
                std::cout << '\n';
            }
            else
            {
                std::cout << "-1\n";
            }
        }
    }
}