#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int delta[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void BFS(vector<pair<int, int>> &start, vector<vector<int>> &tomato)
{
    queue<pair<int, int>> q;
    for (auto s : start)
    {
        q.push(s);
    }

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        int cur = tomato[curX][curY];

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int _x = curX + delta[i][0];
            int _y = curY + delta[i][1];
            if (tomato[_x][_y] == 0 || tomato[_x][_y] > (cur + 1))
            {
                tomato[_x][_y] = cur + 1;
                q.push({_x, _y});
            }
        }
    }
}

int main()
{
    cppIOInitialize();

    int n, m;
    cin >> m >> n; // 입력되는 데이터의 순서를 살펴서 잘 조정해야 한다. 어떤 문제는 가로가, 또다른 문제는 세로가 먼저 입력될 수 있다.

    vector<vector<int>> tomato(1002, vector<int>(1002, -1));
    vector<pair<int, int>> points;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int n;
            cin >> n;

            tomato[i][j] = n;

            if (n == 1)
            {
                points.push_back({i, j});
            }
        }
    }

    BFS(points, tomato);

    int result = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int t = tomato[i][j];
            if (t == 0)
            {
                cout << -1 << "\n";
                return 0;
            }
            result = max(t, result);
        }
    }

    cout << result - 1;

    cout << "\n";

    return 0;
}