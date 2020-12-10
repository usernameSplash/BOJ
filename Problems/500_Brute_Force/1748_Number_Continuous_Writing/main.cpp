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

int NumberWriting(int n)
{
    int ans = 0;
    int digit = 1;

    for (int i = 1; i <= n; i *= 10)
    {
        if (i * 10 <= n)
            ans += (i * 10 - i) * digit;
        else
            ans += (n + 1 - i) * digit;
        digit++;
    }

    return ans;
}

int main()
{

    int n;

    cin >> n;

    int ans = NumberWriting(n);

    cout << ans;

    cout << "\n";

    return 0;
}
