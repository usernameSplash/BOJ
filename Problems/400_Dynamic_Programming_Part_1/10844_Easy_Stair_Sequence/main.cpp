#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long getCaseStairSequence(int n)
{
    long long answer = 0;
    const int mod = 1000000000;

    int dp[101][11] = {0};
    for(int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= 100; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j == 0)
                dp[i][j] = dp[i-1][j+1];
            else 
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
        }
    }

    for(int i = 0; i <= 9; i++)
    {
        answer += static_cast<long long>(dp[n][i]);
    }

    return answer % mod;
}

int main()
{
    int n;
    cin >> n;

    cout << getCaseStairSequence(n);
    cout << "\n";

    return 0;
}