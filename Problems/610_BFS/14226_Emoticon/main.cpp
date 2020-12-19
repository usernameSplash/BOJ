#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(int n, vector<vector<int>> &check)
{
    check[1][0] = 0;

    queue<pair<int, int>> q;

    q.push({1, 0});

    while (!q.empty())
    {
        int s = q.front().first;
        int c = q.front().second;
        int cur = check[s][c];
        q.pop();

        if (check[s][s] == 200000)
        {
            check[s][s] = min(check[s][s], cur + 1);
            q.push({s, s});
        }

        if (s + c <= n && check[s + c][c] == 200000)
        {
            check[s + c][c] = min(check[s + c][c], cur + 1);
            q.push({s + c, c});
        }

        if (s > 0 && check[s - 1][c] == 200000)
        {
            check[s - 1][c] = min(check[s - 1][c], cur + 1);
            q.push({s - 1, c});
        }
    }
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    vector<vector<int>> check(1001, vector<int>(1001, 200000));

    BFS(n, check);

    int ans = 200000;
    for (auto c : check[n])
    {
        ans = min(ans, c);
    }

    cout << ans;

    cout << "\n";

    return 0;
}