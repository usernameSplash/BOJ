#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


int DP0[41] = {0};
int DP1[41] = {0};


int main()
{
    cppIOInitialize();

    DP0[0] = 1;
    DP1[1] = 1;

    for(int i = 2; i <= 40; i++)
    {
        DP0[i] = DP0[i-2] + DP0[i-1];
        DP1[i] = DP1[i-2] + DP1[i-1];
    }
    
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        cout << DP0[n] << " " << DP1[n] << "\n";
    }

    return 0;
}
