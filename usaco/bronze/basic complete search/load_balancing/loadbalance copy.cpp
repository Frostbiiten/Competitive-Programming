#include <iostream>
#include <algorithm>
#include <cstring>

typedef std::pair<int, int> coordinate;

int main()
{
    //std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, b;
    std::cin >> n >> b;

    coordinate coords[n];
    int xPoints[n], yPoints[n];
    int quads[4] = {0, 0, 0, 0};

    for (int i = 0; i < n; ++i)
    {
        std::cin >> coords[i].first >> coords[i].second;
        xPoints[i] = yPoints[i] = i;
    }

    std::sort(xPoints, xPoints + n, [&coords](int a, int b){ return coords[a].first < coords[b].first; });
    std::sort(yPoints, yPoints + n, [&coords](int a, int b){ return coords[a].second < coords[b].second; });

    int xInd = n >> 1;
    int yInd = xInd;
    int x = (coords[xPoints[xInd]].first >> 1) << 1;
    int y = (coords[yPoints[yInd]].second >> 1) << 1;

    for (int i = 0; i < n; ++i)
    {
        coordinate cur = coords[i];
        ++quads[((cur.first > x) << 1) + (cur.second > y)];
    }

    int maxInd, max = -1;
    for (int i = 0; i < 4; ++i)
    {
        if (quads[i] > max)
        {
            max = quads[i];
            maxInd = i;
        }
    }

    bool diff = true;
    do
    {
        int maxX = maxInd >> 1;
        int maxY = maxInd - (maxX << 1);

        int xOffset = -((maxX << 1) - 1);
        int yOffset = -((maxY << 1) - 1);

        int newCoords[2] = { ((maxX + xOffset) << 1) + maxY, (maxX << 1) + maxY + yOffset };

        bool xmove = quads[newCoords[0]] < quads[newCoords[1]];
        if (xmove)
        {
            xInd = std::min(std::max(0, xInd + xOffset), n - 1);
            std::cout << "move x " << xOffset << '\n';
        }
        else
        {
            yInd = std::min(std::max(0, yInd + yOffset), n - 1);
            std::cout << "move y " << yOffset << '\n';
        }

        int oldX = x, oldY = x;
        if (xmove) x = coords[xPoints[xInd]].first;
        else y = coords[yPoints[yInd]].second;
        x += ((oldX < x) << 1) - 1;
        y += ((oldY < y) << 1) - 1;

        int old[4];
        memcpy(old, quads, sizeof(quads));
        memset(quads, 0, sizeof(quads));

        for (int i = 0; i < n; ++i)
        {
            coordinate cur = coords[i];
            ++quads[((cur.first > x) << 1) + (cur.second > y)];
        }

        //diff = false;
        for (int i = 0; i < 4; ++i)
        {
            if (quads[i] != old[i])
            {
                //diff = true;
                //break;
            }
        }
    }
    while (diff);

    return 0;
}