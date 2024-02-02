#include <iostream>
#include <vector>

int main()
{
    for (int test = 1; test <= 20; test += 1)
    {
        int t = test;

        std::vector<int> nums;
        nums.reserve(t);

        for (int i = 1; i <= t; ++i)
        {
            nums.push_back(i);
        }

        for (int j = 0; j < t; ++j)
        {
            nums.push_back(nums[j]);
            nums.erase(nums.begin() + j);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            //if (nums[i] % 2 != 0 && (nums[i] + 3) % 8 != 0)
            std::cout << nums[i] << ' ';
        }
        std::cout << '\n';
    }
}

// 2 4 6 8 10 12 14 16 18 1 5 9 13 17 3 11 19 15 7

// [!div 2]
// 1 5 9 13 17 3 11 19 15 7

// [-1]
// 0 4 8 12 16 2 10 18 14 6

// [div 4]
// 2 10 18 14 6

// 3 11 19 15 7

// [-2]
// 0 8 16 12 4

// [!div 8]
// 12 4

// 15 7

// [-4]
// 8 0

// [!div 16]
// 8 0

// 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 1 5 9 13 17 21 25 29 33 37 41 45 49 7 15 23 31 39 47 11 27 43 19 3 35

// 1 5 9 13 17 21 25 29 33 37 41 45 49 7 15 23 31 39 47 11 27 43 19 3 35

// 7 15 23 31 39 47 11 27 43 19 3 35

// 7 15 23 31 39 47 11 27 43 19 3 35


// 2 4 6 8 10 12 14 16 18 3 7 11 15 1 9 17 13 

// [! DIV 2] - 8 numbers rounded up
// 3 7 11 15 1 9 17 13 

// [DIV 2 ROUND]
// 1 3 5 7 0 4 8 6 

// [DIV 2] - 4 numbers
// 0 4 8 6 

// [DIV 2 ROUND]
// 0 2 4 3 

// [! DIV 2] - 1 number ?? wtf --> if odd start do goofy?
// 3 

// 2 4 6 8 10 12 14 16 18 20 3 7 11 15 19 5 13 1 17 9

// [! DIV 2]
// 3 7 11 15 19 5 13 1 17 9

// [FORCE DIV 2]
// 1 3 5 7 9 2 6 0 8 4

// [DIV 2]
// 2 6 0 8 4

// [FORCE DIV 2]
// 1 3 0 4 2

// [DIV 2]
// 1 3 0 4 2

// 2 4 6 8 10 12 14 16 18 1 5 9 13 17 3 11 19 15 7
// 1 5 9 13 17 3 11 19 15 7 [NO DIV 2]
// 0 2 4 6 8 1 5 9 7 3 [FORCE DIV 2]
// 1 5 9 7 3 [NO DIV 2]
// 0 2 4 3 1 [FORCE DIV 2]
// 3 1 [NO DIV 2]
// 1 0 [FORCE DIV 2]
// 1 0 [NO DIV 2] ??

// 2 4 6 8 10 12 14 16 18 1 5 9 13 17 3 11 19 15 7
// 1 5 9 13 17 3 11 19 15 7 [NO DIV 2]
// 0 2 4 6 8 1 5 9 7 3 [FORCE DIV 2]
// 1 5 9 7 3 [NO DIV 2]
// 0 2 4 3 1 [FORCE DIV 2]
// 3 1 [NO DIV 2]
// 1 0 [FORCE DIV 2]
// 1 0 [NO DIV 2] ??