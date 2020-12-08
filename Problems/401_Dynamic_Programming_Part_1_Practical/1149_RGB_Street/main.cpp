#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long dp[1000001] = {0};

int RGBStreet(int (*data)[3], int n)
{
    int dp[1000][3];
    
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = data[0][i];
    }
    
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + data[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + data[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + data[i][2];
    }

    return min( min( dp[n-1][0], dp[n-1][1] ), dp[n-1][2] );
}

int main()
{
    int n;
    cin >> n;

    int data[1000][3];

    for(int i = 0; i < n; i++)
    {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    cout << RGBStreet(data, n);
    cout << "\n";

    return 0;
}