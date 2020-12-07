#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Tiling2xN(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << Tiling2xN(n);

    cout << "\n";

    return 0;
}