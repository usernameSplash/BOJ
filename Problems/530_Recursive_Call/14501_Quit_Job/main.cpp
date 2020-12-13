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

int ans = 0;

void Calculate(vector<int> &d, vector<int> &p, int sum, int i)
{
    int n = d.size();
    if (i > n)
        return;
    if (i == n)
    {
        ans = max(ans, sum);
        return;
    }

    Calculate(d, p, sum + p[i], i + d[i]);
    Calculate(d, p, sum, i + 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> days(n);
    vector<int> prices(n);

    for (int i = 0; i < n; i++)
    {
        cin >> days[i] >> prices[i];
    }

    Calculate(days, prices, 0, 0);

    cout << ans << "\n";

    return 0;
}
