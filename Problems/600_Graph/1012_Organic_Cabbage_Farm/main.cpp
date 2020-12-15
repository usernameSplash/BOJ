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

bool check[52][52] = {0};
int cabbage[52][52] = {0};

int delta[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool BFS(int x, int y)
{
    if(check[x][y] || cabbage[x][y] == 0)
        return false;
    
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});

    
    while(!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int _x = curX + delta[i][0];
            int _y = curY + delta[i][1];
            if(cabbage[_x][_y] == 1 && check[_x][_y] == false)
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

    int t;
    cin >> t;

    while(t--)
    {
        int m, n, k;
        cin >> m >> n >> k;
        
        for(int i = 0; i < n + 1; i++)
            for(int j = 0; j < m + 1; j++)
            {
                check[i][j] = false;
                cabbage[i][j] = 0;
            }

        for(int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            cabbage[y+1][x+1] = 1;
        }

        int ans = 0;
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(BFS(i, j))
                {
                    ans++;
                }
            }
        }
        cout << ans;
        cout << "\n";
    }

    return 0;
}