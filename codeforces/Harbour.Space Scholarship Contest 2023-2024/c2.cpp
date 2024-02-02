#include <iostream>
#include <cassert>
#include <vector>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int t, k;
    std::cin >> t;

    std::vector<int> path;
    path.reserve(1000);

    for (int test = 1; test < t; ++test)
    {
        //std::cin >> k;
        k = 11;
        std::multiset<int> visited;
        std::vector<std::multiset<int>> v;
        v.resize(1001);
        path.clear();

        int current = k;
        while (current > 0)
        {
            int depth = path.size();
            path.push_back(current);
            if (current == 1) break;

            bool f = false;

            for (int i = current / 2; i > 0; --i)
            {
                if (current % i == 0 && visited.count(i) < 2 && !v[depth].count(i))
                {
                    std::cout << std::string(path.size(), ' ') << i << " is a factor of " << current << ", exploring " << current - i << " (" << i << " -> " << visited.count(i) << ")" <<  '\n';
                    visited.insert(i);
                    current -= i;
                    f = true;
                    break;
                }
            }

            if (!f)
            {
                int last = path[depth - 1] - path[depth];
                visited.erase(visited.lower_bound(last));
                v[depth - 1].insert(last);
                current = path[depth - 1];
                path.pop_back();
                path.pop_back();
            }
        }

        for (int i = 0; i < path.size(); ++i) std::cout << path[i] << ' ';
        std::cout << '\n';
    }
    
    return 0;
}