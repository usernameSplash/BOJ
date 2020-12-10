#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int FillTiles(int n)
{
    int dp[31] = {0};
    dp[0] = 1;
    
    for(int i = 2; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for(int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << FillTiles(n);

    cout << "\n";

    return 0;
}