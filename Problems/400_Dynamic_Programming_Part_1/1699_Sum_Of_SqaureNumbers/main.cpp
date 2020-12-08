#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int getSumOfSquare(int n)
{
    int dp[100001];
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        dp[i] = 100000;
        for(int j = 1; j*j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << getSumOfSquare(n);
    cout << "\n";

    return 0;
}