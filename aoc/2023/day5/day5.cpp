#include <iostream>
#include <queue>
#include <string>

std::pair<int, int> arr[20000];
bool visited[20000];

int main()
{
    freopen("input.in", "r", stdin);
    //freopen("input.out", "w", stdout);

    std::string directions;
    std::cin >> directions;

    int lineCount = 774;

    auto hash = [&](std::string input) -> int{
        int hash = (input[0] - 'A')
         + (input[1] - 'A') * 26
         + (input[2] - 'A') * 26;
        return hash;
    };

    int orig = -1;

    std::string a, l, r;
    for (int i = 0; i < lineCount; ++i)
    {
        std::cin >> a >> l >> r;
        
        int aHash = hash(a);
        if (orig == -1)
        {
            orig = aHash;
        }

        arr[aHash] = {hash(l), hash(r)};
    }


    std::queue<int> q;
    q.push(orig);

    int currentInstruction = 0;
    int count = 0;

    while (!q.empty())
    {
        int current = q.front();
        if (current == hash("ZZZ")) break;

        std::cout << current << '\n';

        q.pop();

        bool direction = directions[currentInstruction];
        ++currentInstruction;
        ++count;
        if (currentInstruction == directions.size()) currentInstruction = 0;

        int next = direction ? arr[current].second : arr[current].first;

        q.push(next);
    }

    std::cout << count << '\n';
    return 0;
}