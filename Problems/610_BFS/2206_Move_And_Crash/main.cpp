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

bool ok(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

int delta[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int MAX = 2000001;

void BFS(int n, int m, vector<vector<int>> &a, vector<vector<vector<int>>> &v)
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    
    v[0][0][0] = 1;

    while(!q.empty())
    {
        int x, y, w;
        tie(x, y, w) = q.front();
        q.pop();

        int cur = v[x][y][w];

        for(int i = 0; i < 4; i++)
        {
            int dx = x + delta[i][0];
            int dy = y + delta[i][1];

            if(ok(dx, dy, n, m))
            {
                if(a[dx][dy] == 0)
                {
                    if(v[dx][dy][w] == MAX)
                    {
                        v[dx][dy][w] = cur + 1;
                        q.push({dx, dy, w});
                    }
                }
                else
                {
                    if(w == 0 && v[dx][dy][w + 1] == MAX)
                    {
                        v[dx][dy][w + 1] = cur + 1;
                        q.push({dx, dy, w+1});
                    }
                }
            }
        }
    }
}

int main()
{
    cppIOInitialize();
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(2, MAX)));

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        
        int j = 0;
        for(auto c : s)
        {
            if(c == '0')
            {
                a[i][j] = 0;
                j++;
            }
            else
            {
                a[i][j] = 1;
                j++;
            }
        }
    }

    BFS(n, m, a, v);

    int ans = min(v[n - 1][m - 1][0], v[n - 1][m - 1][1]);

    if(ans == MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    
    cout << "\n";

    return 0;
}
