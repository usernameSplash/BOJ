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

int flip(vector<vector<int>> data, int mask)
{
    int n = data.size();

    for (int j = 0; j < n; j++)
    {
        if ((mask & (1 << j)) > 0)
        {
            for (int k = 0; k < n; k++)
            {
                data[j][k] ^= 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += data[j][i];
        }
        temp = max(temp, n - temp);
        ans += temp;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++)
        {
            d[i][j] = (s[j] == 'H' ? 1 : 0);
        }
    }

    const int MAX = 1 << n;

    int ans = 0;
    for (int i = 0; i < MAX; i++)
    {
        ans = max(ans, flip(d, i));
    }

    cout << (n * n - ans);

    cout << "\n";

    return 0;
}
