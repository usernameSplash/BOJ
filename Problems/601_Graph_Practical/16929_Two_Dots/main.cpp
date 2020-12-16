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

bool ok(int x, int y, int n, int m)
{
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool DFS(int x, int y, int n, int m, int px, int py, vector<string>& v, vector<vector<bool>>& check)
{
    if(check[x][y] == true)
        return true;
    
    char color = v[x][y];
    check[x][y] = true;

    for(int i = 0; i < 4; i++)
    {
        int dX = x + delta[i][0];
        int dY = y + delta[i][1];
        
        if(!ok(dX, dY, n, m))
            continue;
        
        int cur = v[dX][dY];

        if(color != cur)
            continue;
        
        if(dX == px && dY == py)
            continue;

        if (DFS(dX, dY, n, m, x, y, v, check))
            return true;
    }
    return false;
}

int main()
{
    cppIOInitialize();
    
    int n, m;
    cin >> n >> m;

    vector<string> v;
    vector<vector<bool>> check(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!check[i][j])
            {
                if (DFS(i, j, n, m, -1, -1, v, check))
                {
                    cout << "Yes" << "\n";

                    return 0;
                }
            }
        }
    }

    cout << "No" << "\n";

    return 0;
}