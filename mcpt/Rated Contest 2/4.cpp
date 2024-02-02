#include <iostream>
#include <algorithm>
#include <climits>
#include <set>

// array of sets
// arr[i], i is one-way trip time
// set elements are current progress to end
std::set<int> topArr[13]; // to top
std::set<int> bottomArr[13]; // to bottom

// time, dir
std::pair<int, int> questions[200000];

int main()
{
    int n, q;
    std::cin >> n >> q;

    // a = one-way length, b = starting, d = direction
    int a, b, d;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a >> b >> d;
        if (d == 1) topArr[a].insert(a - b);
        else bottomArr[a].insert(b);
    }

    // questions
    int t, s;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> t >> s;

        int bestDelay = INT_MAX;

        // check off by one ?? can he wait 0 time?
        for (int tripLen = 1; tripLen <= 12; ++tripLen)
        {
            // time remaining, travelling in the same direction
            int timeRemaining = t % (2 * tripLen);

            int topDelay = INT_MAX; 
            int bottomDelay = INT_MAX;

            
            if (topArr[tripLen].size())
            {
                auto iter = topArr[tripLen].lower_bound(timeRemaining);
                if (iter == topArr[tripLen].end())
                {
                    --iter;
                }
                topDelay = *iter - timeRemaining;
                if (topDelay < 0)
                {
                    bottomDelay = tripLen + topDelay;
                    topDelay += tripLen * 2;
                }
            }


            if (bottomArr[tripLen].size())
            {
                auto iter = bottomArr[tripLen].lower_bound(timeRemaining);
                if (iter == bottomArr[tripLen].end())
                {
                    --iter;
                }
                int bottomDel = *iter - timeRemaining;
                if (bottomDel < 0)
                {
                    int oldTop = topDelay;
                    topDelay = std::min(topDelay, std::max(0, tripLen + bottomDel));
                    bottomDel += tripLen * 2;
                }

                bottomDelay = std::min(bottomDelay, bottomDel);
            }

            if (s == 1 && topDelay != INT_MAX) topDelay += tripLen;
            if (s == 2 && bottomDelay != INT_MAX) bottomDelay += tripLen;

            bestDelay = std::min({bestDelay, topDelay, bottomDelay});
        }

        std::cout << bestDelay << '\n';
    }
    
    return 0;
}