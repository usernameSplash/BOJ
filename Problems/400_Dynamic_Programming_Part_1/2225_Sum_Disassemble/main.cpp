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

long long SumDisassemble(int n, int k)
{
    const int mod = 1000000000;
    long long dp[201][201] = {0};

    for(int i = 0; i <= 200; i++)
    {
        dp[0][i] = 1; // 0부터 n까지 k개의 정수를 더해 0을 만드는 경우는 모두 하나이다.
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    
    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << SumDisassemble(n, k);
    cout << "\n";

    return 0;
}