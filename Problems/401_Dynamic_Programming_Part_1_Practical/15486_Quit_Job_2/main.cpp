#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Calculate(vector<int> &d, vector<int> &p)
{
    int n = d.size();
    int result = 0;
    vector<int> dp(n + 100, 0);

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            dp[i] = max(dp[i], dp[i - 1]);
        if (i + d[i] <= n)
            dp[i + d[i]] = max(dp[i + d[i]], dp[i] + p[i]);
    }

    for (int i = 0; i <= n; i++)
    {
        result = max(result, dp[i]);
    }

    return result;
}

int main()
{
    cppIOInitialize();
    int n;
    cin >> n;

    int result;
    vector<int> days(n);
    vector<int> prices(n);

    for (int i = 0; i < n; i++)
    {
        cin >> days[i] >> prices[i];
    }

    result = Calculate(days, prices);

    cout << result << "\n";

    return 0;
}
