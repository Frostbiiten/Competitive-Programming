#include <iostream>
#include <set>
#include <sstream>

int main()
{
    int bag[5];
    int total = 0;
    for (int i = 0; i < 5; ++i)
    {
        std::cin >> bag[i];
        total += bag[i];
    }

    auto getStates = [](int b[5]){
        std::stringstream s;
        for (int i = 0; i < 5; ++i) s << b[i] << ' ';
        return s.str();
    };

    std::set<std::string> states;
    states.insert(getStates(bag));

    int turns = 1;
    while (true)
    {
        int newBags[5];
        memcpy(newBags, bag, sizeof (bag));

        for (int i = 0; i < 5; ++i)
        {
            if (bag[i] * 5 > total)
            {
                newBags[i] -= 4;
                for (int j = 0; j < 5; ++j)
                {
                    if (i != j) ++newBags[j];
                }
            }
        }

        std::string s = getStates(newBags);
        if (states.find(s) == states.end())
        {
            states.insert(s);
            memcpy(bag, newBags, sizeof (bag));
        }
        else
        {
            states.clear();
            break;
        }

        if (!states.size()) break;
        ++turns;
    }

    std::cout << turns << '\n';

    return 0;
}