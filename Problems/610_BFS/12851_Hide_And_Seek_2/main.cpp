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

pair<int, int> BFS(int n, int k, vector<int> &check)
{
    if (n > k)
    {
        return {n - k, 1};
    }
    else if (n == k)
    {
        return {0, 1};
    }

    check[n] = 0;
    queue<int> q;
    q.push(n);

    int kind = 0;
    int min = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        vector<int> next(3);

        next[0] = cur + 1;
        next[1] = cur - 1;
        next[2] = cur * 2;

        for (auto num : next)
        {
            if (ok(num) && (check[num] == -1 || check[num] == check[cur] + 1))
            {
                check[num] = check[cur] + 1;

                if (num == k)
                {
                    if (kind == 0)
                    {
                        min = check[k];
                        kind++;
                    }
                    else if (check[num] == min)
                    {
                        kind++;
                    }
                }
                q.push(num);
            }
        }
    }
    return {check[k], kind};
}

int main()
{
    cppIOInitialize();

    int n, k;
    cin >> n >> k;

    vector<int> check(100001, -1);

    pair<int, int> result = BFS(n, k, check);

    cout << result.first << "\n";
    cout << result.second << "\n";

    return 0;
}