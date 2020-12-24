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
    
    bool zero = false;
    int indexSum = 0;

    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
            zero = true;
        indexSum += s[i] - '0';
    }

    sort(s.begin(), s.end(), [](const char a, const char b) {return a > b;});

    if(indexSum % 3 || !zero)
        cout << -1;
    else
        cout << s;
    

    cout << "\n";

    return 0;
}