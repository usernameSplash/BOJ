#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int ans = 0;

    while(n >= 2 && m >= 1 && (n + m) >= k + 3)
    {
        n -= 2;
        m -= 1;
        ans += 1;
    }

    cout << ans;

    cout << "\n";

    return 0;
}