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

int BFS(int x, int y, int n, int m, vector<vector<int>> &check, vector<vector<int>> &maze)
{
    check[x][y] = 1;

    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        int cur = check[curX][curY];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int _x = curX + delta[i][0];
            int _y = curY + delta[i][1];
            if (maze[_x][_y] == 1 && check[_x][_y] == -1)
            {
                check[_x][_y] = cur + 1;
                q.push({_x, _y});
            }
        }

        if (check[n][m] != -1)
            return check[n][m];
    }
    return check[n][m];
}

int main()
{
    cppIOInitialize();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> check(102, vector<int>(102, -1));
    vector<vector<int>> maze(102, vector<int>(102, 0));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            maze[i + 1][j + 1] = (s[j] == '0') ? 0 : 1;
        }
    }

    int result = BFS(1, 1, n, m, check, maze);

    cout << result;

    cout << "\n";

    return 0;
}