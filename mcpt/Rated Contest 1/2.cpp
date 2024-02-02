#include <ios>
#include <iostream>
#include <vector>

std::vector<int> graph[100000];

int count(int start)
{
    // no cycles right?
    int c = 0;

    for (auto child : graph[start]) c += count(child);

    // children + self
    return c + 1;
}

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
        graph[a].push_back(b);
    }

    std::cin >> a >> b;

    // count a
    int ac = count(a);
    int bc = count(b);
    if (ac > bc) std::cout << "A\n";
    else if (ac < bc) std::cout << "B\n";
    else std::cout << "Either\n";

    return 0;
}