#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int IntegerTriangle(int data[][501], int n)
{
    int dp[501][501] = {0};
    dp[1][1] = data[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + data[i][j];
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result = max(result, dp[n][i]);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    int data[501][501] = {0};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> data[i][j];
        }
    }
    cout << IntegerTriangle(data, n);
    cout << "\n";

    return 0;
}