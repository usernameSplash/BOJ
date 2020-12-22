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
    vector<string> data(n);

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    int r;
    cin >> r;
    while (r--) 
    {
        int no, dir;
        cin >> no >> dir;
        no--;

        vector<int> d(n);
        d[no] = dir;

        for(int i = no; i > 0; i--)
        {
            if(data[i-1][2] != data[i][6])
            {
                d[i-1] = -d[i];
            }
        }
        for(int i = no; i < n - 1; i++)
        {
            if(data[i+1][6] != data[i][2])
            {
                d[i+1] = -d[i];
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(d[i] == 0) continue;
            else if(d[i] > 0)
            {
                char temp = data[i][7];
                for(int j = 7; j > 0; j--)
                {
                    data[i][j] = data[i][j-1];
                }
                data[i][0] = temp;
            }
            else
            {
                char temp = data[i][0];
                for(int j = 0; j < 7; j++)
                {
                    data[i][j] = data[i][j+1];
                }
                data[i][7] = temp;
            }   
        }
    }

    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(data[i][0] == '1')
        {
            ans += 1;
        }
    }

    cout << ans;

    cout << "\n";

    return 0;
}
