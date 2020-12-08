#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int AscendingNumber(int n)
{
    int dp[1001][10] = {0};
    const int mod = 10007;

    for (int i = 0; i < 1001; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i < 1001; i++)
    {
        dp[i][0] = 1;
        for(int j = 1; j <= 9; j++)
        {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
        }
    }

    int result = 0;

    for(int i = 0; i <= 9; i++)
    {
        result = (result + dp[n][i]) % mod;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    cout << AscendingNumber(n);
    cout << "\n";

    return 0;
}

