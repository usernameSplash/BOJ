#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int WineTest(int data[], int n)
{
    int dp[10001] = {0};

    dp[1] = data[1];
    dp[2] = data[1] + data[2];
    dp[3] = max({data[1] + data[3], data[2] + data[3], dp[2]});

    for (int i = 4; i <= n; i++)
    {
        int val1 = dp[i - 3] + data[i - 1] + data[i];
        int val2 = dp[i - 2] + data[i];
        int val3 = dp[i - 1];

        dp[i] = max({val1, val2, val3});
    }

    int result = 0;

    for (int i = 1; i <= n; i++)
    {
        result = max(result, dp[i]);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    int data[10001] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> data[i];
    }

    cout << WineTest(data, n);
    cout << "\n";

    return 0;
}