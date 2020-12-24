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

    vector<int> a(n);

    bool check1 = n >= (m + k - 1);
    bool check2 = n <= m * k;
    
    if(!(check1 && check2))
    {
        cout << -1 << "\n";
        return 0;
    }
    else 
    {
        for(int i = 1; i <= n; i++)
        {
            a[i-1] = i;
        }

        int idx = 0;
        for(int i = 1; i <= m; i++)
        {
            int temp = min(idx + k, n - m + i);

            reverse(a.begin() + idx, a.begin() + temp);

            idx = temp;
        }
        
        for(auto aa : a)
        {
            cout << aa << " ";
        }
        cout << "\n";
        return 0;
    }
    

    return 0;
}