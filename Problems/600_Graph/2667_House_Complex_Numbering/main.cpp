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

bool check[27][27] = {0};
int house[27][27] = {0};

int delta[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int BFS(int x, int y)
{
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});

    int result = 1;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int _x = curX + delta[i][0];
            int _y = curY + delta[i][1];
            if (house[_x][_y] == 1 && check[_x][_y] == false)
            {
                result += 1;
                check[_x][_y] = true;
                q.push({_x, _y});
            }
        }
    }
    return result;
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
        {
            check[i][j] = false;
        }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            house[i + 1][j + 1] = (s[j] == '0') ? 0 : 1;
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!check[i][j] && house[i][j] == 1)
            {
                ans.push_back(BFS(i, j));
            }
        }
    }

    cout << ans.size() << "\n";

    sort(ans.begin(), ans.end());
    for (auto n : ans)
    {
        cout << n << "\n";
    }

    return 0;
}