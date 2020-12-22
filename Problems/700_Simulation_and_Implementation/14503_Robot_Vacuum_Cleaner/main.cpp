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
// 북동남서
int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool ok(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

int main()
{
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;

    vector<vector<int>> a(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    while(true)
    {
        a[x][y] = 2;

        bool stop = true;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + delta[i][0];
            int ny = y + delta[i][1];

            if(!ok(nx, ny, n, m))
                continue;
            
            if(a[nx][ny] == 0)
                stop = false;
        }
        if(stop)
        {
            int nx = x - delta[d][0];
            int ny = y - delta[d][1];

            if(!ok(nx, ny, n, m))
                break;

            if(a[nx][ny] == 1)
                break;
            
            x = nx;
            y = ny;

            continue;
        }
        
        d = (d + 3) % 4;
        int nx = x + delta[d][0];
        int ny = y + delta[d][1];

        if(ok(nx, ny, n, m) && a[nx][ny] == 0)
        {
            x = nx;
            y = ny;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 2)
                ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
