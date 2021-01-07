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


vector<int> d1(1000000);
vector<int> d2(1000000);
vector<int> result(2000000);


int main()
{
    cppIOInitialize();
    
    int s1, s2;
    
    cin >> s1 >> s2;

    for(int i = 0; i < s1; i++)
    {
        cin >> d1[i];
    }
    for(int i = 0; i < s2; i++)
    {
        cin >> d2[i];
    }

    int i = 0, l = 0, r = 0;

    while(l < s1 && r < s2)
    {
        if(d1[l] < d2[r])
            result[i++] = d1[l++];
        else 
            result[i++] = d2[r++];
    }

    while(l < s1)
    {
        result[i++] = d1[l++];
    }

    while(r < s2)
    {
        result[i++] = d2[r++];
    }

    for(int i = 0; i < s1+s2; i++)
    {
        cout << result[i] << " ";
    }

    cout << "\n";
    return 0;
}