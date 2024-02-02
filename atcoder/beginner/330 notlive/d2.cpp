#include <iostream>

bool arr[2000][2000];
int oRowCount[2000];
int oColCount[2000];

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::cin >> n;

    // scan each row
    char c;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> c;
            bool set = c == 'o';
            arr[i][j] = set;
            oRowCount[i] += set;
            oColCount[j] += set;
        }
    }

    // total number of L's
    uint64_t count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // if set 'o'
            if (arr[i][j])
            {
                int rowLeft = oRowCount[i] - 1;
                int colLeft = oColCount[j] - 1;

                if (rowLeft > 0 && colLeft > 0)
                {
                    count += rowLeft * colLeft;
                }
            }
        }
    }

    std::cout << count << '\n';

    return 0;
}