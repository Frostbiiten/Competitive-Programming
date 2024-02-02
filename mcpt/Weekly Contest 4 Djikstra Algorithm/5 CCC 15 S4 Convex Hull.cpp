#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cstdint>
#include <map>

struct path
{
    int other;
    int time;
    int wear;
};

// 2000x2000 array instead?
std::vector<path> graph[2000];

// first wear (remaining), second time
std::map<int, int> states[2000];

// first is time range, second is wear range
int minT[2000]; int maxT[2000];
int minK[2000]; int maxK[2000];
bool visited[2000];
uint32_t queued[2000];

int main()
{
    memset(minT, INT_MAX, sizeof(minT));
    memset(minK, INT_MAX, sizeof(minK));
    memset(queued, INT_MAX, sizeof(queued));
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int k, n, m;
    std::cin >> k >> n >> m;

    int a, b, t, h;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b >> t >> h;
        --a; --b;

        // bidirectional
        graph[a].push_back(path{b, t, h});
        graph[b].push_back(path{a, t, h});
    }

    // sort wear from least to greatest
    for (int i = 0; i < 2000; ++i) std::sort(graph[i].begin(), graph[i].end(), [](path& a, path& b){ return a.wear < b.wear; });

    // start/end
    std::cin >> a >> b; --a; --b;

    // queue
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push({0, a});

    // initial state
    states[a][k] = 0;
    
    // is this necessary???
    minT[0] = maxT[0] = 0;
    minK[0] = maxK[0] = k;

    while (!q.empty())
    {
        int current = q.top().second;
        q.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (auto state : states[current])
        {
            for (auto neighbor : graph[current])
            {
                int newK = state.first - neighbor.wear;
                if (newK <= 0) break; // broken hull, next neighbors will have greater wear

                int newT = state.second + neighbor.time;

                int otherNode = neighbor.other;

                // is it objectively worse?
                if (newK <= minK[otherNode] && newT >= maxT[otherNode]) continue;

                // is it objectively better?
                if (newK >= maxK[otherNode] && newT <= minT[otherNode]) states[otherNode].clear();

                minT[otherNode] = std::min(minT[otherNode], newT);
                maxT[otherNode] = std::max(maxT[otherNode], newT);
                minK[otherNode] = std::min(minK[otherNode], newK);
                maxK[otherNode] = std::max(maxK[otherNode], newK);

                auto f = states[otherNode].find(newK);
                if (f == states[otherNode].end()) states[otherNode][newK] = newT;
                else f->second = std::min(f->second, newT);

                if (newT < queued[otherNode])
                {
                    q.push({newT, otherNode});
                    queued[otherNode] = newT;
                }
            }
        }
    }

    std::pair<int, int> bestState = {0, INT_MAX};
    for (auto state : states[b]) if (state.second < bestState.second) bestState = state;
    if (bestState.second == INT_MAX) bestState.second = -1;
    std::cout << bestState.second << '\n';

    return 0;
}