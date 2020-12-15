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


bool checkBipariteGraph(vector<vector<int>> &g, vector<int> &check, int start)
{
    check[start] = 1;

    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto next : g[v])
        {
            if(check[next] == 0)
            {
                q.push(next);
                check[next] = check[v] * -1;
            }
            else 
            {
                if(check[next] == check[v])
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    cppIOInitialize();

    int k;
    cin >> k;

    while(k--)
    {
        int v, e;
        cin >> v >> e;

        vector<vector<int>> g(20001);
        vector<int> check(20001, 0);

        for(int i = 0; i < e; i++)
        {
            int from, to;
            cin >> from >> to;

            g[from].push_back(to);
            g[to].push_back(from);
        }

        bool result = true;
        for(int i = 1; i <= v; i++)
        {
            if(check[i] == 0)
                result &= checkBipariteGraph(g, check, i);
            if(!result)
                break;
        }

        if(result)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        
        cout << "\n";
    }

    return 0;
}