#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int CainCalendar(int m, int n, int x, int y)
{
    int ans = x;
    for (int i = x; i <= n * m; i += m)
    {
        if ((i - 1) % n + 1 == y)
            break;
        ans += m;
    }
    if (ans > n * m)
    {
        ans = -1;
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, x, y;

        cin >> M >> N >> x >> y;

        int ans = CainCalendar(M, N, x, y);

        cout << ans;

        cout << "\n";
    }
    return 0;
}
