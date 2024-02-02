#include <float.h>
#include <ios>
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

const std::pair<int, int> offset[8] = {
    {2, 1},
    {1, 2},
    {-2, 1},
    {-1, 2},
    {2, -1},
    {1, -2},
    {-2, -1},
    {-1, -2},
};

int visited[2000][2000];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n;
    std::cin >> n;

    int limit = (n * (n + 3) ) / 5;

    // default (0) is unvisited
    // 1 is covered
    // 2 is knight

    auto print = [&](){
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cout << visited[i][j] << ' ';
            }
            std::cout << '\n';
        }
    };

    // default state of upper-left
    for (int def = 1; def <= 2; ++def)
    {
        bool pass = true;
        int knights = 0;
        int remaining = n * n;
        
        // reset
        memset(visited, 0, sizeof(visited));
        visited[0][0] = def;

        //std::queue<std::pair<int, int>> q;
        auto comp = [&](std::pair<int, int> a, std::pair<int, int> b){ return visited[a.first][a.first] > visited[b.first][b.second]; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> q(comp);
        q.push({0, 0});

        // basic bfs
        while (!q.empty())
        {
            std::pair<int, int> current = q.top();
            int currentVisited = visited[current.first][current.second];
            q.pop();

            // possible directions
            for (int i = 0; i < 8; ++i)
            {
                std::pair<int, int> newP = {current.first + offset[i].first, current.second + offset[i].second};
                if (newP.first < 0 || newP.second < 0 || newP.first >= n || newP.second >= n) continue;

                // only if valid
                int v = visited[newP.first][newP.second];
                int newV = (currentVisited == 1) + 1;
                    
                // only if unvisited
                if (v != 2)
                {
                    if (newV == 2)    
                    {
                        // if above limit, 'fail'
                        if (knights > limit)
                        {
                            std::cout << "kys\n";
                            pass = false;
                            break;
                        }
                    
                        ++knights;
                        --remaining;
                        std::cout << remaining << '\n';

                        //std::cout << knights << '\n';
                    }

                    if (v != newV)
                    {
                        // set
                        visited[newP.first][newP.second] = newV;

                        // queue
                        q.push(newP);
                    }

                    //print();
                    //std::cout << '\n';
                }
            }

            if (!pass) break;
        }

        // *
        if (remaining > 0) pass = false;

        if (pass)
        {
            std::cout << "possible\n";
            print();
            return 0;
        }
    }

    std::cout << "-1";

    return 0;
}