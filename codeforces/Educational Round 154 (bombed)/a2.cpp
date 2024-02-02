#include <iostream>
#include <queue>
#include <cmath>
#include <set>

bool np[100000000];

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    for (int i = 3; i <= 10000; i += 2)
    {
        if (np[i]) continue;
        for (int j = i << 1; j < 100000000; j += i) np[j] = true;
    }

    std::set<std::string> pr;

    for (int i = 13; i < 100000000; i += 2)
    {
        if ((i & 1) && !np[i]) pr.insert(std::to_string(i));
    }

    int cases, n;
    std::cin >> cases;
    for (int t = 0; t < cases; ++t)
    {
        std::cin >> n;
        std::queue<int> q;
        q.push(n);

        bool f = false;
        while(q.size())
        {
            auto c = q.front(); q.pop();
            std::string str = std::to_string(c);
        
            if (str.size() > 2)
            {
                for (int i = 1; i <= str.size(); ++i)
                {
                    int test = std::stoi(str.substr(0, i - 1) + str.substr(i, str.size() - i));
                    q.push(std::stoi(str.substr(0, i - 1) + str.substr(i, str.size() - i)));
                }
            }

            if ((c & 1) == 0) continue;
            if (c >= 100000000)
            {
                bool p = true;
                for (int i = 3; i <= std::sqrt(c); i += 2)
                {
                    if (c % i == 0)
                    {
                        p = false;
                        break;
                    }
                }
                if (!p) continue;
            } else if (np[c]) continue;

            std::cout << c << '\n';
            f = true;
            break;
        }

        if (!f) std::cout << "-1\n";
    }

    return 0;
}