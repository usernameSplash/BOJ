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

int delta[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}}; // 나이트의 행마
int n;                                                                                      //체스판의 한 변의 길이

int BFS(pair<int, int> &start, pair<int, int> &end, vector<vector<int>> &chess)
{
    int x = start.first;
    int y = start.second;

    int _x = end.first;
    int _y = end.second;

    if (x == _x && y == _y)
    {
        return 0;
    }

    chess[x][y] = 0;

    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        int cur = chess[curX][curY];
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int dX = curX + delta[i][0];
            int dY = curY + delta[i][1];

            if (!(0 <= dX && dX < n && 0 <= dY && dY < n))
                continue;

            if (chess[dX][dY] == 0)
            {
                chess[dX][dY] = cur + 1;
                q.push({dX, dY});
            }

            if (dX == _x && dY == _y)
                return chess[dX][dY];
        }
    }
    return -1;
}

int main()
{
    cppIOInitialize();

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<vector<int>> chess(301, vector<int>(301));
        pair<int, int> start;
        pair<int, int> end;

        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        int result = BFS(start, end, chess);

        cout << result;

        cout << "\n";
    }
    return 0;
}