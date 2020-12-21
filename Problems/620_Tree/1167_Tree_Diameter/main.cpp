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

void BFS(int start, vector<vector<pair<int,int>>> &a, vector<int> &v)
{
    queue<int> q;
    q.push(start);
    v[start] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto x : a[cur])
        {
            int n = x.first;
            int w = x.second;

            if(v[n] != -1)
                continue;

            v[n] = v[cur] + w;
            q.push(n);
        }
    }
}

int main()
{
    cppIOInitialize();
    
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> a(100001);
    vector<int> visited(100001, -1);
    vector<int> visited2(100001, -1);

    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;

        while (true)
        {
            int x, y;
            cin >> x;
            if(x == -1)
            {
                break;
            }
            cin >> y;

            a[v].push_back({x, y});
        }
        
    }

    int start = 1;
    BFS(start, a, visited);

    int v = 0;
    int farthest = 0;
    for(int i = 1; i <= n; i++)
    {
        if(farthest < visited[i])
        {
            farthest = visited[i];
            v = i;
        }
    }

    BFS(v, a, visited2);

    farthest = 0;
    for(int i = 1; i <= n; i++)
    {
        farthest = max(farthest, visited2[i]);
    }

    cout << farthest;
    cout << "\n";
    return 0;
}