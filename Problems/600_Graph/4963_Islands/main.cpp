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

int delta[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool BFS(int x, int y, vector<vector<bool>> &check, vector<vector<int>> &island)
{
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int _x = curX + delta[i][0];
            int _y = curY + delta[i][1];
            if (island[_x][_y] == 1 && check[_x][_y] == false)
            {
                check[_x][_y] = true;
                q.push({_x, _y});
            }
        }
    }
    return true;
}

int main()
{
    cppIOInitialize();

    while (true)
    {
        vector<vector<bool>> check(52, vector<bool>(52, false));
        vector<vector<int>> island(52, vector<int>(52, 0));

        int n, m;
        cin >> m >> n;

        if (n == 0 && m == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> island[i + 1][j + 1];
            }
        }

        int result = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!check[i][j] && island[i][j] == 1)
                {
                    result += 1;
                    BFS(i, j, check, island);
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}