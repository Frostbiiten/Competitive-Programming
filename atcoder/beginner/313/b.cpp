#include <iostream>
#include <cstring>
#include <queue>

int main()
{
    int n, m, stronger, weaker;
    std::cin >> n >> m;

    std::uint64_t masks[n], top = UINT64_MAX >> (64 - n);
    memset(masks, 0, sizeof(masks));

    for (int i = 0; i < m; ++i)
    {
        std::cin >> stronger >> weaker;
        --stronger; --weaker;
        masks[stronger] |= 1ull << weaker;
    }

    int id = -1;
    for (int i = 0; i < n; ++i)
    {
        std::uint64_t less = 0;

        std::queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            less |= 1ull << cur;

            for (int shift = 0, current = masks[cur]; current > 0; ++shift, current >>= 1)
            {
                if (current & 1)
                {
                    q.push(shift);
                }
            }
        }

        if (less == top)
        {
            if (id != -1)
            {
                id = -1;
                break;
            }
            id = i + 1;
        }
    }

    std::cout << id << '\n';

    return 0;
}