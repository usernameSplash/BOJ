#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    int n, k;
    cin >> n >> k;

    int answer[5000];
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            q.push(q.front());
            q.pop();
        }
        answer[i] = q.front();
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < n - 1; i++)
    {
        cout << answer[i] << ", ";
    }
    cout << answer[n - 1] << ">\n";
}