#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long PinaryNumber(int n)
{
    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]);
    }

    return dp[n];
}

int main()
{
    int n;
    
    cin >> n;

    cout << PinaryNumber(n);

    cout << "\n";

    return 0;
}