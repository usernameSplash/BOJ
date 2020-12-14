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

bool check(vector<int> &data, int s, int bitmask)
{
    int n = data.size();
    
    int sum = 0;
    for(int j = 0; j < n; j++)
    {
        if((bitmask & (1 << j)) > 0)
        {
            sum += data[j];
        }
    }

    if(sum == s)
        return true;
    else
        return false;
    
}

int main()
{
    cppIOInitialize();
    
    int n, s, ans = 0;
    cin >> n >> s;

    vector<int> data(n);
    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for(int i = 1; i < (1 << n); i++)
    {
        if(check(data, s, i))
            ans++;
    }
    cout << ans;
    cout << "\n";

    return 0;
}
