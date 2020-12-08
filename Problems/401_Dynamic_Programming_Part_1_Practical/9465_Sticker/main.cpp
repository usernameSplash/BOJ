#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Sticker(int data[][100001], int n)
{
    int dp[3][100001] = {0};

    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + data[0][i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + data[1][i];
    }

    return max({dp[0][n], dp[1][n], dp[2][n]});
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int data[2][100001] = {0};

        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> data[i][j];
            }
        }

        cout << Sticker(data, n);
        cout << "\n";
    }
    return 0;
}