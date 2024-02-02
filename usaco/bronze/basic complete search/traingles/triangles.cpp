// http://www.usaco.org/index.php?page=viewproblem2&cpid=784

#include <iostream>
#include <vector>
#include <map>

typedef std::pair<int, int> coordinate;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;
    std::cin >> n;

    coordinate points[n];
    std::map<int, std::vector<int>> horizontals, verticals;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> points[i].first >> points[i].second;
        verticals[points[i].first].push_back(i);
        horizontals[points[i].second].push_back(i);
    }

    int max = 0;
    for (auto& horizontal : horizontals)
    {
        for (int i = 0; i < horizontal.second.size(); ++i)
        {
            int index1 = horizontal.second[i];
            coordinate point1 = points[index1];
            for (int j = 0; j < horizontal.second.size(); ++j)
            {
                int index2 = horizontal.second[j];
                coordinate point2 = points[index2];

                int width = std::abs(point2.first - point1.first);
                if (width == 0) continue;

                int localMax = 0;
                for (auto ind : verticals[point1.first])
                {
                    localMax = std::max(localMax, std::abs(point1.second - points[ind].second));
                }
                for (auto ind : verticals[point2.first])
                {
                    localMax = std::max(localMax, std::abs(point1.second - points[ind].second));
                }
                max = std::max(max, localMax * width);
            }
        }
    }

    std::cout << max << '\n';
    return 0;
}