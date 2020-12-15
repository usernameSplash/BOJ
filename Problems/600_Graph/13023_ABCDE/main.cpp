#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    cppIOInitialize();
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > edges;
    vector<vector<int>> g(2000); //인접 리스트
    bool w[2000][2000] = {0}; //인접 행렬

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
        edges.push_back({y, x});

        g[x].push_back(y);
        g[y].push_back(x);

        w[x][y] = true;
        w[y][x] = true;
    }
    
    m *= 2;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int A = edges[i].first;
            int B = edges[i].second;

            int C = edges[j].first;
            int D = edges[j].second;

            if(A == B || A == C || A == D || B == C || B == D || C == D)
                continue;
            
            if(!w[B][C])
                continue;
            
            for(auto E : g[D])
            {
                if(E == A || E == B || E == C || E == D)
                {
                    continue;
                }
                cout << 1 << "\n";
                
                return 0;
            }
        }
    }

    cout << 0 << "\n";

    return 0;
}
