#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Zoo(int n)
{
    int dp[100001][3];
    const int mod = 9901;

    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = ((dp[i-1][0] + dp[i-1][1]) % mod + dp[i-1][2]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % mod;
    }

    return ((dp[n-1][0] + dp[n-1][1]) % mod + dp[n-1][2]) % mod;
}

int main()
{
    int n;
    cin >> n;

    cout << Zoo(n);
    cout << "\n";

    return 0;
}