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

bool check[1001] = {0};
vector<vector<int>> g(1001);

void goBFS(int v)
{
    check[v] = true;

    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();

        for(auto next : g[vertex])
        {
            if(!check[next])
            {
                q.push(next);
                check[next] = true;
            }
        }
    }
}

int main()
{
    cppIOInitialize();

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;

        g[from].push_back(to);
        g[to].push_back(from);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!check[i])
        {
            goBFS(i);
            ans++;
        }
    }

    cout << ans;
    cout << "\n";


    return 0;
}
