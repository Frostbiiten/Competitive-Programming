#include <iostream>
#include <vector>
#include <cstring>

int main()
{
    std::cin.tie(0); std::cout.tie(0); std::ios_base::sync_with_stdio(0);

    int n, m, c; std::string s;
    std::cin >> n >> m >> s;

    std::vector<int> index[m];
    int color[n], counter[m];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> color[i];
        --color[i];
        index[color[i]].push_back(i);
    }

    // set begin index to last
    for (int i = 0; i < m; ++i) counter[i] = index[i].size() - 1;

    // print character by character
    for (int i = 0; i < n; ++i)
    {
        // get current char color
        int col = color[i];

        // print current, increment, loop
        std::cout << s[index[col][counter[col]]];
        ++counter[col];
        if (counter[col] >= index[col].size()) counter[col] = 0;
    }

    return 0;
}