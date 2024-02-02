// http://www.usaco.org/index.php?page=viewproblem2&cpid=615

#include <iostream>
#include <cstring>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int buckets[2], m;
    std::cin >> buckets[0] >> buckets[1] >> m;

    int max = buckets[1];

    std::queue<int> q;
    q.push(0);

    bool v[1000];
    memset(v, false, sizeof(v));

    while(!q.empty())
    {
        int val = q.front();
        q.pop();

        for (int i = 0; i < 2; ++i)
        {
            int newVal = val + buckets[i];
            if (v[newVal]) continue;

            if (newVal < m)
            {
                max = std::max(newVal, max);
                v[newVal] = true;
                q.push(newVal);
            }
            else if (newVal == m)
            {
                std::cout << m << '\n';
                return 0;
            }
        }
    }

    std::cout << max << '\n';
    return 0;
}