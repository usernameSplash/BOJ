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

bool cmp (pair<int, int> &p, pair<int, int> &q)
{
    if(p.second < q.second)
        return true;
    else if (p.second > q.second)
        return false;
    else
        return p.first < q.first;   
}

int solve(vector<pair<int, int>> &meetings)
{
    int temp = 0;
    int result = 0;

    for(auto m : meetings)
    {
        if(m.first >= temp)
        {
            temp = m.second;
            result += 1;
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        data[i] = {x, y};
    }

    sort(data.begin(), data.end(), cmp);
    
    int result = solve(data);

    cout << result;

    cout << "\n";

    return 0;
}
