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

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second > b.second)
        return true;
    else if (a.second < b.second)
        return false;
    else
    {
        return a.first > b.first;
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> jewel(n);
    vector<int> bag(m);

    for (int i = 0; i < n; i++)
    {
        cin >> jewel[i].first >> jewel[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> bag[i];
    }

    make_heap(jewel.begin(), jewel.end(), cmp);
    sort(bag.begin(), bag.end());

    long long ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (auto j : jewel)
        {
            if (bag[i] >= j.first)
            {
                //Todo
            }
        }
    }

    cout << ans;

    cout << "\n";

    return 0;
}
