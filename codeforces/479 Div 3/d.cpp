// https://codeforces.com/contest/977/problem/D
#include <functional>
#include <iostream>
#include <vector>
#include <map>

typedef std::map<std::uint64_t, int> mm;
mm graph;

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    std::uint64_t n, in;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        ++graph[in];
    }

    // try each as first
    std::function<bool(std::uint64_t, mm)> dfs;
    std::vector<std::uint64_t> l;
    dfs = [&dfs, &l](std::uint64_t n, mm v) -> bool
    {
        if (v.size() == 1)
        {
            l.push_back(n);
            return true;
        }

        for (int i = 0; i < 2; ++i)
        {
            std::uint64_t num;
            if (i == 0)
            {
                num = n * 2;
            }
            else
            {
                if (n % 3 == 0) num = n / 3;
                else break;
            }

            if (v.count(num))
            {
                mm vnew = v;
                --vnew[num];
                if (vnew[num] == 0) vnew.erase(num);
                if (dfs(num, vnew))
                {
                    l.push_back(n);
                    return true;
                }
            }
        }

        return false;
    };

    l.reserve(n);
    for (auto p :  graph)
    {
        l.clear();
        mm vnew = graph;
        vnew.erase(p.first);
        if (dfs(p.first, graph)) break;
    }

    for (int i = l.size() - 1; i >= 0; --i)
    {
        std::cout << l[i] << ' ';
    }
    std::cout << '\n';
}