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

bool check(int n, vector<int> &btn)
{
    while (true)
    {
        int temp = n % 10;
        for (auto b : btn)
        {
            if (temp == b)
            {
                return false;
            }
        }
        n /= 10;

        if (n == 0)
            break;
    }
    return true;
}

int Tetromino(int target, vector<vector<int>> &data)
{
    int answer = 0;
    int n = data.size();
    int m = data[0].size();

    vector<vector<pair<int, int>>> delta = {
        {{0, 1}, {0, 2}, {0, 3}},
        {{1, 0}, {2, 0}, {3, 0}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {1, 0}, {2, 0}},
        {{0, 1}, {0, 2}, {1, 2}},
        {{1, 0}, {2, 0}, {2, -1}},
        {{0, 1}, {0, 2}, {-1, 2}},
        {{1, 0}, {2, 0}, {2, 1}},
        {{0, 1}, {0, 2}, {1, 0}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 1}, {1, 0}, {1, 1}},
        {{0, 1}, {-1, 1}, {-1, 2}},
        {{1, 0}, {1, 1}, {2, 1}},
        {{0, 1}, {1, 1}, {1, 2}},
        {{1, 0}, {1, -1}, {2, -1}},
        {{0, 1}, {0, 2}, {-1, 1}},
        {{0, 1}, {0, 2}, {1, 1}},
        {{1, 0}, {2, 0}, {1, 1}},
        {{1, 0}, {2, 0}, {1, -1}},
    };
    int blocks = 19;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < blocks; k++)
            {
                bool flag = true;
                int sum = data[i][j];
                for (int cell = 0; cell < 3; cell++)
                {
                    int x = i + delta[k][cell].first;
                    int y = j + delta[k][cell].second;

                    if (0 <= x && x < n && 0 <= y && y < m)
                    {
                        sum += data[x][y];
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag && answer < sum)
                {
                    answer = sum;
                }
            }
        }
    }

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> data(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> data[i][j];
        }
    }

    int ans = Tetromino(n, data);

    cout << ans;

    cout << "\n";

    return 0;
}
