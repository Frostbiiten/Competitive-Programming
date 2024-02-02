#include <iostream>
#include <queue>
#include <cstdint>

typedef std::pair<int, int> coord;
const int offsets[4] = {-9, -7, 7, 9};

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    // default beth/bennystate
    uint64_t bethState = 0;
    uint64_t bennyState = 0;

    int spotId = 0;
    std::string currentRow;
    for (int row = 0; row < 8; ++row)
    {
        // scan one line/row at a time
        std::cin >> currentRow;

        // iterate x
        for (int col = 0; col < 8; ++col)
        {
            bethState |= (uint64_t)(currentRow[col] == 'A') << spotId;
            bennyState |= (uint64_t)(currentRow[col] == 'B') << spotId;
            ++spotId;
        }
    }

    int maxMoves = 0;

    // attempt from each starting point
    for (int startSpot = 0; startSpot < 64; ++startSpot)
    {
        // skip if not starting bit
        if (!((bethState >> startSpot) & 1)) continue;

        // queue of spot, moves, bethstate
        std::queue<std::tuple<int, int, uint64_t>> q;
        q.push({startSpot, 0, bennyState});

        while (!q.empty())
        {
            auto front = q.front();
            int currentSpot = std::get<0>(front);
            int currentMoves = std::get<1>(front);
            uint64_t currentState = std::get<2>(front);
            q.pop();

            // get current state row and column
            int row = currentSpot / 8;
            int col = currentSpot - row * 8;

            // check possible step directions
            int end = 4 - 2 * (row > 5);
            for (int stepDir = 2 * (row <= 1); stepDir < end; ++stepDir)
            {
                // bound checking
                if (!(stepDir & 1) && col <= 1) continue;
                if ((stepDir & 1) && col > 5) continue;

                // ONE diagonal offset
                int currentOffset = offsets[stepDir];
                
                // tile being stepped over
                int stepOver = currentSpot + currentOffset;
                int landing = currentSpot + currentOffset * 2;
                
                if (
                    ((currentState >> stepOver) & 1) && // benny tile present
                    !((currentState >> landing) & 1) && // landing tile should be empty (check benny)
                    !((bethState >> landing) & 1) // landing tile should be empty (check beth)
                )
                {
                    // unset spot stepped over in state
                    uint64_t newState = ~((~currentState) | (1ull << stepOver));

                    int newMoves = currentMoves + 1;

                    // unset spot jumped over
                    q.push({landing, newMoves, newState});
                    
                    // check max
                    if (maxMoves < newMoves) maxMoves = newMoves;
                }
            }
        }
    }

    std::cout << maxMoves << '\n';
    return 0;
}