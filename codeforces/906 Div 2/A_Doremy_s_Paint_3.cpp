#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    std::map<int, int> nums;
    int t, n, c;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        nums.clear();

        for (int i = 0; i < n; ++i)
        {
            std::cin >> c;
            if (nums.size() > 2) continue;

            auto f = nums.find(c);
            if (f != nums.end()) ++(f->second);
            else nums[c] = 1;
        }

        if (nums.size() == 1)
        {
            std::cout << "Yes\n";
        }
        else if (nums.size() == 2)
        {
            int diff = std::abs(nums.begin()->second - std::next(nums.begin())->second);

            if (diff <= 1) std::cout << "Yes\n";
            else std::cout << "No\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
}