#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long dp[1000001] = {0};

long long PlusOneTwoThree(int n)
{
    const int mod = 1000000009;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
    }

    return dp[n] % mod;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        cout << PlusOneTwoThree(n);

        cout << "\n";
    }
    return 0;
}