#include <iostream>
#include <string>
#include <algorithm> //얘를 include하지 않으면 BOJ에서 에러가 발생했다.

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    cppIOInitialize();
    string s;
    cin >> s;

    for (char c = 'a'; c <= 'z'; c++)
    {
        auto it = find(s.begin(), s.end(), c);

        if (it == s.end())
        {
            cout << "-1 ";
        }
        else
        {
            cout << it - s.begin() << " ";
        }
    }

    cout << "\n";

    return 0;
}