#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

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
    check[n] = 0;
    queue<int> q;
    q.push(n);

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
            if (ok(num) && check[num] == -1)
            {
                check[num] = cur;

                if (num == k)
                    return check[k];

                q.push(num);
            }
        }
    }
    return check[k];
}

stack<int> solve(int n, int k, vector<int> &check)
{
    BFS(n, k, check);

    stack<int> result;

    int i = k;
    while (i != n)
    {
        result.push(i);
        i = check[i];
    }
    result.push(n);

    return result;
}

int main()
{
    cppIOInitialize();

    int n, k;
    cin >> n >> k;

    vector<int> check(100001, -1);

    stack<int> result = solve(n, k, check);

    cout << result.size() - 1 << "\n";

    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
    cout << "\n";

    return 0;
}