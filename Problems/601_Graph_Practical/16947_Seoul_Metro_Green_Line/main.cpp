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

// 순환선을 찾아 check 배열에 반영한다.
// x : DFS를 실시할 역의 번호
// p : 이전 역의 번호(와리가리 방지)
int findCycle(int x, int p, vector<vector<int>> &v, vector<int> &check)
{
    // -2 : x번째 역이 싸이클은 아니지만 재귀 내에서 싸이클을 찾음 -> 어떤 역의 다음 역이 우연히 싸이클의 시작점일 경우.
    // -1 : 싸이클 못 찾음
    // 0 ~ n-1 : x번째 역이 싸이클의 시작점임

    if (check[x] == 1)
        return x;

    check[x] = 1;

    for (auto y : v[x])
    {
        if (p == y)
            continue;

        int res = findCycle(y, x, v, check); // 다음 DFS를 수행한다.

        if (res == -2)
            return -2;

        if (res >= 0) //이미 방문한 역을 다시 방문한 경우 -> 싸이클
        {
            check[x] = 2;
            if (res == x) // 자기 자신이 싸이클의 시작점일 경우
                return -2;
            else
                return res;
        }
    }
    return -1;
}

int main()
{
    cppIOInitialize();

    int n; //역의 개수
    cin >> n;

    vector<vector<int>> v(n); // 역의 연결 상태 (인접 리스트)
    vector<int> dist(n, -1);  // dist[i] = i번째 역과 순환선 사이의 거리
    vector<int> check(n, 0);  // 0 : 미방문, 1 : 방문, 2 : 순환선

    for (int i = 0; i < n; i++)
    {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    findCycle(0, -1, v, check);

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 2)
        {
            dist[i] = 0;
            q.push(i);
        }
        else
        {
            dist[i] = -1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto next : v[cur])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    for (auto i : dist)
    {
        cout << i << " ";
    }

    cout << "\n";
    return 0;
}