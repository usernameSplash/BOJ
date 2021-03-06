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

void goDFS(int v)
{
    check[v] = true;
    cout << v << " ";

    for(auto next : g[v])
    {
        if(!check[next])
        {
            check[next] = true;
            goDFS(next);
        }
    }
}

void goBFS(int v)
{
    check[v] = true;

    queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int vertex = q.front();
        cout << vertex << " ";
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

    int n, m, v;
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;

        g[from].push_back(to);
        g[to].push_back(from);
    }
    for(int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }

    goDFS(v);
    cout << "\n";
    
    for(int i = 1; i <= n; i++)
    {
        check[i] = false;
    }

    goBFS(v);
    cout << "\n";


    return 0;
}
