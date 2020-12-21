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

void BFS(vector<vector<int>> &a, vector<int> &v)
{
    queue<int> q;
    q.push(1);
    v[1] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto x : a[cur])
        {
            if(v[x] == -1)
            {
                v[x] = cur;
                q.push(x);
            }
        }
    }
}

int main()
{
    cppIOInitialize();
    
    int n;
    cin >> n;

    vector<vector<int>> a(100001);
    vector<int> visited(100001, -1);

    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;

        a[x].push_back(y);
        a[y].push_back(x);
    }

    BFS(a, visited);

    for(int i = 2; i <= n; i++)
    {
        cout << visited[i] << "\n";
    }

}