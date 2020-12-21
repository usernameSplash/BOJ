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


int BFS(vector<vector<int>> & a, vector<bool> & v) 
{
    v[0] = true;
    
    queue<int> q;
    q.push(0);

    int result = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next : a[cur])
        {
            if(v[next])
                continue;
            v[next] = true;
            q.push(next);
            result++;
        }
    }

    return result;
}

int main()
{
    cppIOInitialize();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n);
    vector<bool> v(n, false);

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        a[x - 1].push_back(y - 1);
        a[y - 1].push_back(x - 1);
    }

    cout << BFS(a, v);

    cout << "\n";

    return 0;
}
