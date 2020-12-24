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
    string s;
    cin >> s;

    vector<int> num;
    vector<int> sign;

    int cur = 0;

    for(auto c : s)
    {
        if(c == '+' || c == '-')
        {
            if(c == '+')
            {
                sign.push_back(1);
            }
            else
            {
                sign.push_back(-1);
            }
            num.push_back(cur);
            cur = 0;
        }
        else
        {
            cur *= 10;
            cur += c - '0';
        }
    }
    num.push_back(cur);

    int ans = num[0];
    int delta = 1;
    int n = num.size();
    
    for(int i = 1; i < n; i++)
    {
        if(sign[i-1] < 0)
            delta = -1;
        ans += delta * num[i];
    }

    cout << ans;

    cout << "\n";

    return 0;
}
