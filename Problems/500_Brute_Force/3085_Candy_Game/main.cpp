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

int check(vector<string> &data)
{
    int n = data.size();
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        int temp = 1;
        for(int j = 1; j < n; j++)
        {
            if(data[i][j-1] == data[i][j])
            {
                temp++;
            }
            else 
            {
                temp = 1;
            }
            if(ans < temp)
            {
                ans = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        int temp = 1;
        for(int j = 1; j < n; j++)
        {
            if(data[j-1][i] == data[j][i])
            {
                temp++;
            }
            else 
            {
                temp = 1;
            }
            if(ans < temp)
            {
                ans = temp;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<string> data(n);

    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((j + 1) < n)
            {
                swap(data[i][j], data[i][j+1]);
                int temp = check(data);
                
                if(ans < temp)
                    ans = temp;

                swap(data[i][j], data[i][j+1]);
            }

            if((i + 1) < n)
            {
                swap(data[i][j], data[i+1][j]);
                int temp = check(data);
                
                if(ans < temp) 
                    ans = temp;

                swap(data[i][j], data[i+1][j]);
            }
        }
    }
    
    cout << ans;
    cout << "\n";

    return 0;
}