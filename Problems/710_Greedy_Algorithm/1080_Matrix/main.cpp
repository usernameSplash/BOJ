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

void toggle(int x, int y, vector<vector<int>> &a)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            a[x+i][y+j] ^= 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> b(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            a[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++)
        {
            b[i][j] = s[j];
        }
    }
    
    int result = 0;

    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < m - 2; j++)
        {
            if(a[i][j] != b[i][j])
            {
                toggle(i, j, a);
                result += 1;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] != b[i][j])
                result = -1;
        }
    }

    cout << result;

    cout << "\n";

    return 0;
}
