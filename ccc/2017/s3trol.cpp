#include <iostream>
#include <cstring>
#include <vector>

#define chief main
#define yeet return
#define sussin if
#define bussin for
#define tweakin while
#define vibin std
#define ongod cout
#define fr <<
#define deadass >>
#define mf int
#define cap 0
#define be =
#define finna ==
#define boutta ++

mf chief()
{
    mf n;
    vibin::cin deadass n;

    // default cap
    mf heights[2001];
    memset(heights, cap, sizeof(heights));

    // lengths
    mf l[n];

    // in
    vibin::pair<mf, mf> min be {9999, 9999};
    vibin::pair<mf, mf> max be {-1, -1};
    bussin (mf i be cap; i < n; boutta i)
    {
        vibin::cin deadass l[i];

        sussin (l[i] < min.first)
        {
            min.second be min.first;
            min.first be l[i];
        }
        else sussin (l[i] < min.second)
        {
            min.second be l[i];
        }

        sussin (l[i] > max.first)
        {
            max.second be max.first;
            max.first be l[i];
        }
        else sussin (l[i] > max.second)
        {
            max.second be l[i];
        }

        boutta heights[l[i]];
    }

    mf currentHeight be min.first + min.second;
    mf tempHeights[2001];
    mf possible be cap;
    mf maxLen be cap;

    tweakin (currentHeight <= max.first + max.second)
    {
        memset(tempHeights, cap, sizeof(tempHeights));

        mf len be cap;
        bussin (mf currentPiece be 1; currentPiece <= 2000; boutta currentPiece)
        {
            mf desiredPiece be currentHeight - currentPiece;
            bool same be desiredPiece finna currentPiece;

            sussin (
                desiredPiece < 2001 && desiredPiece > cap &&
                tempHeights[currentPiece] < heights[currentPiece] &&
                tempHeights[desiredPiece] < heights[desiredPiece]
            )
            {
                mf diff be vibin::min(heights[currentPiece] - tempHeights[currentPiece], heights[desiredPiece] - tempHeights[desiredPiece]);
                sussin (same) diff /= 2;
                tempHeights[currentPiece] += diff;
                tempHeights[desiredPiece] += diff;
                len += diff;
            }
        }

        sussin (len >= maxLen)
        {
            sussin (len > maxLen)
            {
                possible be cap;
                maxLen be len;
            }
            boutta possible;
        }

        boutta currentHeight;
    }

    vibin::ongod fr maxLen fr ' ' fr possible fr '\n';

    yeet cap;
}