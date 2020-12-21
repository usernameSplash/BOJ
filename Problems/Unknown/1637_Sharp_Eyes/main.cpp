#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int solve(long long mid, vector<long long> &a, vector<long long> &b, vector<long long> &c)
{
    int result = 0;
    int n = a.size();
    
    for(int i = 0; i < n; i++)
    {
        if(mid >= a[i])
            result += (min(mid, c[i]) - a[i]) / b[i] + 1;
    }

    return result;
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i] >> b[i];
    }

    long long left = 0;
    long long right = 1ll << 32;
    

    while(left < right)
    {
        long long mid = (left + right) >> 1;
        long long result = solve(mid, a, b, c);

        if(result & 1)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (left == 1ll << 32)
        cout << "NOTHING";
    else 
        cout << left << " " << solve(left, a, b, c) - solve(left - 1, a, b, c);

    cout << "\n";

    return 0;
}