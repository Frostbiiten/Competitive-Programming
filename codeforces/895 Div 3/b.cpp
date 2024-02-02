#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t;
    std::cin >> t;

    int traps, room[200];
    for (int test = 0; test < t; ++test)
    {
        std::cin >> traps;
        std::fill_n(room, 200, INT_MAX);

        // fill rooms
        int d, s;
        for (int trap = 0; trap < traps; ++trap)
        {
            std::cin >> d >> s; --d;
            room[d] = std::min(room[d], s);
        }

        // simulate
        bool complete = false;
        for (int i = 1; i <= 500; ++i) // i is not used for indexing
        {
            for (int j = 0; j < i && j < 200; ++j)
            {
                --room[j];
                if (room[j] <= i - j)
                {
                    std::cout << i << '\n';
                    complete = true;
                    break;
                }
            }

            if (complete) break;
        }
    }

    return 0;
}