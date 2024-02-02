#include <iostream>
#include <algorithm>


int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, b;
    std::cin >> n >> b;

    int xPoints[n], yPoints[n];
    int quads[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < n; ++i)
    {
        std::cin >> xPoints[i] >> yPoints[i];
    }

    std::sort(xPoints, xPoints + n);
    std::sort(yPoints, yPoints + n);

    int x = (xPoints[n >> 1] >> 1) << 1;
    int y = (yPoints[n >> 1] >> 1) << 1;



    return 0;
}