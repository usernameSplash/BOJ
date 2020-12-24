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
    int h, w;
    cin >> h >> w;
    
    int ans = 0;

    if(h == 1)
    {
        ans = 1;
    }
    else if(h == 2)
    {
        ans = min(4, (w + 1) / 2);
    }
    else
    {
        if(w >= 7)
        {
            ans = w - 2;
        }
        else 
        {
            ans = min(4, w);
        }
    }

    cout << ans;
    cout << "\n";

    return 0;
}