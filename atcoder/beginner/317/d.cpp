#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, x, y, z;
    std::cin >> n;

    int aoki = 0, takahashi = 0;
    std::pair<int, int> diff[n]; // first is win diff (switch), second is voters

    for (int i = 0; i < n; ++i)
    {
        std::cin >> x >> y >> z;
        diff[i] = {(y - x + 1) / 2, z};

        if (x > y) takahashi += z;
        else aoki += z;
    }

    int diff2 = (aoki - takahashi + 1) / 2;

    if (diff2 <= 0)
    {
        std::cout << "0\n";
        return 0;
    }
    else
    {
        std::sort(diff, diff + n); // get index of first positive num (that actually contributes)
        int posBegin = 0, posLen;

        for (int i = 0; i < n; ++i)
        {
            if (diff[i].first > 0)
            {
                posBegin = i;
                break;
            }
        }

        posLen = n - posBegin;
        std::pair<int, int> matrix[posLen + 1][posLen]; // again, {switch, gain}

        // build first row
        std::pair<int, int> best = {INT_MAX, INT_MAX};
        for (int row = 0; row < posLen; ++row)
        {
            for (int i = 0; i < posLen; ++i)
            {
                if (row == 0)
                {
                    matrix[row][i] = diff[posBegin + i];
                }
                else if (i == row - 1)
                {
                    matrix[row][i] = matrix[row - 1][i];
                }
                else
                {
                    matrix[row][i] = {matrix[row - 1][i].first + diff[posBegin + row - 1].first, matrix[row - 1][i].second + diff[posBegin + row - 1].second};
                }

                if (matrix[row][i].second >= diff2)
                {
                    if (matrix[row][i].first < best.first) best = matrix[row][i];
                }
            }

        }
        
        std::cout << best.first << '\n';
    }
}