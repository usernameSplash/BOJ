#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>

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

void BFS(int n, int m, vector<string> &a, vector<vector<int>> &d)
{
    d[0][0] = 0;
    deque<pair<int, int>> q;

    q.push_front({0, 0});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + delta[i][0];
            int ny = y + delta[i][1];

            if (ok(nx, ny, n, m) && d[nx][ny] == -1)
            {
                if (a[nx][ny] == '0')
                {
                    d[nx][ny] = d[x][y];
                    q.push_front({nx, ny});
                }

                if (a[nx][ny] == '1')
                {
                    d[nx][ny] = d[x][y] + 1;
                    q.push_back({nx, ny});
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
    // vector<vector<vector<int>>> d(100, vector<vector<int>>(100, vector<int>(n + m, -1)));
    vector<vector<int>> d(100, vector<int>(100, -1));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    BFS(n, m, a, d);

    cout << d[n - 1][m - 1];
    cout << "\n";

    return 0;
}