#include <iostream>
#include <stdint.h>
#include <cstring>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    uint32_t v[n][n];
    memset(v, -1, sizeof(v));

    int thing = n*n;
    for (int w = 0; w < k; ++w) 
    {
        v[w][w] = thing;
        --thing;
    }
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            if (!(v[y][x] > thing && v[y][x] <= n*n)) {
                v[y][x] = thing;
                --thing;
            }
        }
    }
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x)
            cout << v[y][x] <<" ";
        cout << "\n";
    }
}
