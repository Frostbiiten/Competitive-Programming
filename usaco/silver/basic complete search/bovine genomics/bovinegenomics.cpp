// http://www.usaco.org/index.php?page=viewproblem2&cpid=739
#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m, val, count = 0;
    char in;
    std::cin >> n >> m;

    int seq[2][n][m];

    for (int group = 0; group < 2; ++group)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cin >> in;
                int val;
                if (in == 'A') val = 0;
                else if (in == 'C') val = 1;
                else if (in == 'G') val = 2;
                else if (in == 'T') val = 3;
                seq[group][i][j] = val;
            }
        }
    }

    std::map<int, int> comp;
    std::uint64_t spottedMask[2];

    for (int a = 2; a < m; ++a)
    {
        for (int b = 1; b < a; ++b)
        {
            for (int c = 0; c < b; ++c)
            {
                spottedMask[0] = spottedMask[1] = 0;
                for (int i = 0; i < n; ++i)
                {
                    for (int group = 0; group < 2; ++group)
                    {
                        int m = (1 << seq[group][i][a]) | (1 << (seq[group][i][b] + 4)) | (1 << (seq[group][i][c] + 8));

                        int id;
                        auto search = comp.find(m);
                        if (search == comp.end())
                        {
                            id = comp.size();
                            comp[m] = id;
                        }
                        else
                        {
                            id = search->second;
                        }

                        spottedMask[group] |= 1ull << id;
                    }
                }

                count += (spottedMask[0] & spottedMask[1]) == 0;
            }
        }
    }

    std::cout << count << '\n';
}