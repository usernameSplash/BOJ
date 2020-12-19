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

int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

void BFS(int n, int m, vector<string> &a, vector<vector<vector<int>>> &d)
{
    d[0][0][0] = 0;
    queue<tuple<int, int, int>> q;

    q.push({0, 0, 0});

    while (!q.empty())
    {
        int x, y, w;
        tie(x, y, w) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + delta[i][0];
            int ny = y + delta[i][1];

            if (ok(nx, ny, n, m))
            {
                if (a[nx][ny] == '0' && d[nx][ny][w] == -1)
                {
                    d[nx][ny][w] = d[x][y][w];
                    q.push({nx, ny, w});
                }

                if (a[nx][ny] == '1' && d[nx][ny][w + 1] == -1)
                {
                    d[nx][ny][w + 1] = d[x][y][w] + 1;
                    q.push({nx, ny, w + 1});
                }
            }
        }
    }
}

int main()
{
    cppIOInitialize();

    int n, m;
    cin >> m >> n;
    vector<string> a(100);
    vector<vector<vector<int>>> d(100, vector<vector<int>>(100, vector<int>(n + m, -1)));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    BFS(n, m, a, d);

    int ans = 201;

    for (auto c : d[n - 1][m - 1])
    {
        if (c == -1)
            continue;
        ans = min(ans, c);
    }

    cout << ans;
    cout << "\n";

    return 0;
}