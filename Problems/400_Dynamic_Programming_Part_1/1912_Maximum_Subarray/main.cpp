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

int getMaximumSubarray(int data[], int n)
{
    int dp[100001] = {0};
    dp[0] = data[0];

    for(int i = 1; i < n; i++)
    {
        dp[i] = -1001; // max값 비교를 위한 초기화.

        dp[i] = max(data[i], dp[i-1] + data[i]);
    }

    int result = -1001;

    for(int i = 0; i < n; i++)
    {
        result = max(result, dp[i]);
    }

    return result;
}

int main()
{
    int n;
    int data[100001];
    
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    
    cout << getMaximumSubarray(data, n);
    cout << "\n";

    return 0;
}