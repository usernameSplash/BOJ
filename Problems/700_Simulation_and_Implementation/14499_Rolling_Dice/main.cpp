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

int n, m, x, y, r;

int delta[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool ok(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool operation1(vector<vector<int>> &data, vector<int> &dice)
{
    int dx = delta[0][0];
    int dy = delta[0][1];

    if (!ok(x + dx, y + dy, n, m))
        return false;
    x += dx;
    y += dy;

    int temp = dice[5];

    dice[5] = dice[2];
    dice[2] = dice[0];
    dice[0] = dice[3];
    dice[3] = temp;

    if (data[x][y] == 0)
    {
        data[x][y] = dice[5];
    }
    else
    {
        dice[5] = data[x][y];
        data[x][y] = 0;
    }
    return true;
}

bool operation2(vector<vector<int>> &data, vector<int> &dice)
{
    int dx = delta[1][0];
    int dy = delta[1][1];

    if (!ok(x + dx, y + dy, n, m))
        return false;

    int temp = dice[5];

    dice[5] = dice[3];
    dice[3] = dice[0];
    dice[0] = dice[2];
    dice[2] = temp;

    x += dx;
    y += dy;

    if (data[x][y] == 0)
    {
        data[x][y] = dice[5];
    }
    else
    {
        dice[5] = data[x][y];
        data[x][y] = 0;
    }

    return true;
}

bool operation3(vector<vector<int>> &data, vector<int> &dice)
{
    int dx = delta[2][0];
    int dy = delta[2][1];

    if (!ok(x + dx, y + dy, n, m))
        return false;

    x += dx;
    y += dy;

    int temp = dice[5];

    dice[5] = dice[1];
    dice[1] = dice[0];
    dice[0] = dice[4];
    dice[4] = temp;

    if (data[x][y] == 0)
    {
        data[x][y] = dice[5];
    }
    else
    {
        dice[5] = data[x][y];
        data[x][y] = 0;
    }

    return true;
}

bool operation4(vector<vector<int>> &data, vector<int> &dice)
{
    int dx = delta[3][0];
    int dy = delta[3][1];

    if (!ok(x + dx, y + dy, n, m))
        return false;

    x += dx;
    y += dy;

    int temp = dice[5];

    dice[5] = dice[4];
    dice[4] = dice[0];
    dice[0] = dice[1];
    dice[1] = temp;

    if (data[x][y] == 0)
    {
        data[x][y] = dice[5];
    }
    else
    {
        dice[5] = data[x][y];
        data[x][y] = 0;
    }

    return true;
}

int main()
{
    cin >> n >> m >> x >> y >> r;

    vector<vector<int>> data(n, vector<int>(m, 0));
    vector<int> dice(6, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> data[i][j];
        }
    }

    bool success = false;

    while (r--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            success = operation1(data, dice);
        }
        else if (op == 2)
        {
            success = operation2(data, dice);
        }
        else if (op == 3)
        {
            success = operation3(data, dice);
        }
        else if (op == 4)
        {
            success = operation4(data, dice);
        }

        if (success)
            cout << dice[0] << "\n";
    }

    return 0;
}
