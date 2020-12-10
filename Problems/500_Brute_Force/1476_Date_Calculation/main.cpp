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

int check(int e, int s, int m)
{
    int _e = 1;
    int _s = 1;
    int _m = 1;
    int result = 1;

    while (e != _e || s != _s || m != _m)
    {
        _e++;
        _s++;
        _m++;
        result++;
        
        if(_e > 15)
            _e -= 15;
        if(_s > 28)
            _s -= 28;
        if(_m > 19)
            _m -= 19;
    }

    return result;
}

int main()
{
    int e, s, m;
    cin >> e >> s >> m;

    int ans = check(e, s, m);

    cout << ans;
    
    cout << "\n";

    return 0;
}