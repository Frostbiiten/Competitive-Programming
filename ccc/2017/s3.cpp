#include <ios>
#include <iostream>
#include <cstring>
#include <vector>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n;
    std::cin >> n;

    // default 0
    int heights[2001];
    memset(heights, 0, sizeof(heights));

    // lengths
    int l[n];

    // in
    std::pair<int, int> min = {9999, 9999};
    std::pair<int, int> max = {-1, -1};
    for (int i = 0; i < n; ++i)
    {
        std::cin >> l[i];

        if (l[i] < min.first)
        {
            min.second = min.first;
            min.first = l[i];
        }
        else if (l[i] < min.second)
        {
            min.second = l[i];
        }

        if (l[i] > max.first)
        {
            max.second = max.first;
            max.first = l[i];
        }
        else if (l[i] > max.second)
        {
            max.second = l[i];
        }

        ++heights[l[i]];
    }

    int currentHeight = min.first + min.second;
    int tempHeights[2001];
    int possible = 0;
    int maxLen = 0;

    while (currentHeight <= max.first + max.second)
    {
        memset(tempHeights, 0, sizeof(tempHeights));

        int len = 0;
        for (int currentPiece = 1; currentPiece <= 2000; ++currentPiece)
        {
            int desiredPiece = currentHeight - currentPiece;
            bool same = desiredPiece == currentPiece;

            if (
                desiredPiece < 2001 && desiredPiece > 0 &&
                tempHeights[currentPiece] < heights[currentPiece] &&
                tempHeights[desiredPiece] < heights[desiredPiece]
            )
            {
                int diff = std::min(heights[currentPiece] - tempHeights[currentPiece], heights[desiredPiece] - tempHeights[desiredPiece]);
                if (same) diff /= 2;
                tempHeights[currentPiece] += diff;
                tempHeights[desiredPiece] += diff;
                len += diff;
            }
        }

        if (len >= maxLen)
        {
            if (len > maxLen)
            {
                possible = 0;
                maxLen = len;
            }
            ++possible;
        }

        ++currentHeight;
    }

    std::cout << maxLen << ' ' << possible << '\n';

    return 0;
}