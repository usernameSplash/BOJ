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

int CardBuying(vector<int> price)
{
    int length = price.size();

    int dp[1001] = {0};

    for (int i = 1; i <= length - 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + price[j]);
        }
    }

    return dp[length - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> price;
    price.push_back(0); //index 0 위치에 더미데이터를 넣어주었다.

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        price.push_back(temp);
    }

    cout << CardBuying(price);
    cout << "\n";

    return 0;
}