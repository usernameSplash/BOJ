#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
int sign[10][10];
int ans[10];

bool check(int index)
{
    int sum = 0;
    for(int i = index; i >= 0; i--)
    {
        sum += ans[i];

        if(sign[i][index] == 0)
        {
            if(sum != 0) 
                return false;
        }
        else if(sign[i][index] > 0)
        {
            if(sum <= 0)
                return false;
        }
        else if(sign[i][index] < 0)
        {
            if(sum >= 0)
                return false;
        }
    }
    return true;
}

bool go(int index)
{
    if(index == n)
    {
        return true;
    }

    if(sign[index][index] == 0)
    {
        ans[index] = 0;
        return check(index) && go(index + 1);
    }

    for(int i = 1; i <= 10; i++)
    {
        ans[index] = i * sign[index][index];
        if(check(index) && go(index + 1))
            return true;
    }
    return false;
}

int main()
{
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(s[cnt] == '0')
                sign[i][j] = 0;
            else if(s[cnt] == '+')
                sign[i][j] = 1;
            else if(s[cnt] == '-')
                sign[i][j] = -1;
            
            cnt++;
        }
    }

    go(0);
    
    for (int i = 0; i < n; i++) 
    {
        cout << ans[i] << " ";
    }

    cout << "\n";

    return 0;
}
