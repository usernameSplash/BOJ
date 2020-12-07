#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long PlusOneTwoThree(int n)
{
    int dp[100001][4] = {0};
    const int mod = 1000000009;

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (j == 1)
                dp[i][j] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
            else if (j == 2)
                dp[i][j] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
            else if (j == 3)
                dp[i][j] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
        }
    }

    // 얘들 long long으로 안 바꾸면 오버플로우 발생해요.
    // answer 뿐만 아니라 ans1, ans2, ans3까지도..
    long long ans1 = static_cast<long long>(dp[n][1]);
    long long ans2 = static_cast<long long>(dp[n][2]);
    long long ans3 = static_cast<long long>(dp[n][3]);
    long long answer = (ans1 + ans2 + ans3) % mod;

    return answer;
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