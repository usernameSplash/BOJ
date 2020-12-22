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

void toggle(int n, vector<int> &a)
{
    int len = a.size();
    for(int i = n - 1; i <= n + 1; i++)
    {
        if(i < 0 || i >= len) continue;
        a[i] ^= 1;
    }
}

pair<bool, int> solve(vector<int> a, vector<int> &b)
{
    int result = 0;
    int n = a.size();

    for(int i = 1; i < n; i++)
    {
        if(a[i-1] != b[i-1])
        {
            toggle(i, a);
            result += 1;
        }
    }

    return {a == b, result};
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n, 0);
    vector<int> b(n, 0);

    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        a[i] = (s[i] == '0') ? 0 : 1;
    }

    cin >> s;
    for(int i = 0; i < n; i++)
    {
        b[i] = (s[i] == '0') ? 0 : 1;
    }

    pair<bool, int> result = solve(a, b);

    toggle(0, a);
    pair<bool, int> result2 = solve(a, b);

    result2.second += 1;

    if(result.first && result2.first)
    {
        cout << min(result.second, result2.second);
    }
    else if(result.first)
    {
        cout << result.second;
    }
    else if(result2.first)
    {
        cout << result2.second;
    }
    else
    {
        cout << -1;
    }

    cout << "\n";

    return 0;
}
