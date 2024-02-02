#include <iostream>
#include <vector>
#include <set>

typedef std::pair<int, int> coffee;
int main()
{
    // bf (k < 6)?
    int n, m, k;
    std::cin >> n >> m >> k;
    coffee coffees[n]; std::vector<coffee> soup[k];
    std::set<coffee> made;
    soup[0].reserve(k);

    int l, g;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> l >> g;
        coffees[i] = {l, g};
        soup[0].push_back(coffees[i]);
    }

    int maxL = 0;

    for (int i = 0; i < n; ++i)
    {
        if (coffees[i].first * m == coffees[i].second) maxL = std::max(maxL, coffees[i].first);
    }

    // each 'row', starting from index 1
    for (int batch = 1; batch < k; ++batch)
    {
        soup[batch].reserve(soup[batch - 1].size() * n);
        for (auto& mix : soup[batch - 1])
        {
            // mix with orig coffee
            for (int c = 0; c < n; ++c)
            {
                coffee newCoffee = {mix.first + coffees[c].first, mix.second + coffees[c].second};
                if (!made.count(newCoffee))
                {
                    if (newCoffee.first * m == newCoffee.second) maxL = std::max(maxL, newCoffee.first);
                    soup[batch].push_back(std::move(newCoffee));
                    made.insert(newCoffee);
                }
            }
        }
    }

    std::cout << maxL << '\n';
    return 0;
}