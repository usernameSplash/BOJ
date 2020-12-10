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

vector<int> LIS(vector<int> data, int n)
{
    vector<int> dp(n);

    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(data[i] > data[j]) 
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp;
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);

    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    vector<int> dp1 = LIS(data, n);
    
    reverse(data.begin(), data.end());

    vector<int> dp2 = LIS(data, n);
    reverse(dp2.begin(), dp2.end());

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        result = max(result, dp1[i] + dp2[i]);
    }

    cout << (result) - 1;

    cout << "\n";

    return 0;
}