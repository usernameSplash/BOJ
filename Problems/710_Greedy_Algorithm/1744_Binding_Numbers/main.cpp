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
    int n;
    cin >> n;

    int zero = 0;
    int one = 0;
    vector<int> pos;
    vector<int> neg;

    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x == 1)
            one++;
        else if(x == 0)
            zero++;
        else if(x > 0)
            pos.push_back(x);
        else if(x < 0)
            neg.push_back(x);
    }

    sort(pos.begin(), pos.end(), [](int a, int b){ return a > b; });
    sort(neg.begin(), neg.end());

    int ans = one;

    n = pos.size();
    if(n % 2)
    {
        pos.push_back(1);
    }

    for(int i = 0; i < n; i += 2)
    {
        ans += pos[i] * pos[i + 1];
    }


    n = neg.size();
    if(n % 2)
    {
        neg.push_back( zero > 0 ? 0 : 1 );
    }

    for(int i = 0; i < n; i += 2)
    {
        ans += neg[i] * neg[i + 1];
    }
    
    cout << ans;

    cout << "\n";

    return 0;
}