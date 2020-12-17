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

bool ok(int x)
{
    return (0 <= x && x <= 100000);
}

int BFS(int n, int k, vector<int> &check)
{
    if(n > k)
    {
        return n - k;
    }

    check[n] = 0;
    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        vector<int> next(3);

        next[0] = cur + 1;
        next[1] = cur - 1;
        next[2] = cur * 2;

        for(auto num : next)
        {
            if(ok(num) && check[num] == -1)
            {
                check[num] = check[cur] + 1;
                
                if(num == k)
                    return check[k];
                
                q.push(num);
            }
        }
    }
    return check[k];

}


int main()
{
    cppIOInitialize();
    
    int n, k;
    cin >> n >> k;

    vector<int> check(100001, -1);

    int result = BFS(n, k, check);

    cout << result << "\n";

    return 0;
}