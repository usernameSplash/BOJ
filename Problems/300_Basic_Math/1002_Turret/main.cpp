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

int sq(int x)
{
    return x * x;
}

int dist(int x1, int y1, int x2, int y2)
{
    return sq(x2 - x1) + sq(y2 - y1);
}

int main()
{
    cppIOInitialize();

    int t;
    cin >> t;

    while (t--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = dist(x1, y1, x2, y2);
        int _r1 = sq(r1 + r2);
        int _r2 = sq(r1 - r2);

        if (x1 == x2 && y1 == y2 && r1 == r2)
            cout << -1 << "\n";
        else if (d == _r1)
            cout << 1 << "\n";
        else if (d > _r1)
            cout << 0 << "\n";
        else if (d < _r1)
        {
            if (d == _r2)
                cout << 1 << "\n";
            else if (d > _r2)
                cout << 2 << "\n";
            else if (d < _r2)
                cout << 0 << "\n";
        }
    }
}
