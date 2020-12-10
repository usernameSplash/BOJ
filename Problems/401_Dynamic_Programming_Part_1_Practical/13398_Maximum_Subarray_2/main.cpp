#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> getMaximumSubarray(vector<int> data, int n)
{
    vector<int> dp(n);

    dp[0] = data[0];

    for(int i = 1; i < n; i++)
    {
        dp[i] = -1001; // max값 비교를 위한 초기화.

        dp[i] = max(data[i], dp[i-1] + data[i]);
    }

    return dp;
}

int solve(int n)
{
    vector<int> data(n);
    vector<int> reversedData(n);
    vector<int> dp1;
    vector<int> dp2;

    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    reversedData.assign(data.begin(), data.end());
    reverse(reversedData.begin(), reversedData.end());

    dp1 = getMaximumSubarray(data, n);
    
    dp2 = getMaximumSubarray(reversedData, n);
    reverse(dp2.begin(), dp2.end());

    int result = -1001;
    for(int i = 0; i < n; i++)
    {
        int val = (dp1[i] + dp2[i] - data[i]);
        result = max(result, val);
    }

    for(int i = 1; i < n-1; i++)
    {
        int val = (dp1[i-1] + dp2[i+1]);
        result = max(result, val);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n);
    cout << "\n";

    return 0;
}