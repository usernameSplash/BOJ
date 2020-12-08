#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int GIS(int data[], int n)
{
    int dp[1001] = {0};
    dp[0] = data[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = data[i];
        for (int j = 0; j < i; j++)
        {
            if (data[i] > data[j])
            {
                dp[i] = max(dp[i], dp[j] + data[i]);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, dp[i]);
    }

    return result;
}

int main()
{
    int n;
    int data[1001];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    cout << GIS(data, n);

    cout << "\n";

    return 0;
}