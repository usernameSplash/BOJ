#include <iostream>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<int>> matrix(2188, vector<int>(2188, 0));
vector<int> result(3, 0);

bool same(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (matrix[x][y] != matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int n)
{
    if (same(x, y, n))
    {
        result[matrix[x][y] + 1] += 1;
        return;
    }

    int m = n / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            solve(x + i * m, y + j * m, m);
        }
    }
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    solve(0, 0, n);

    cout << result[0] << "\n"
         << result[1] << "\n"
         << result[2];

    cout << "\n";

    return 0;
}