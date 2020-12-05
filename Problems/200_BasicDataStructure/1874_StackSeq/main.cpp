#include <iostream>
#include <stack>

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

    int n = 0;
    cin >> n;

    int m = 0;
    stack<int> s;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x > m)
        {
            while (x > m)
            {
                m++;
                s.push(m);
                ans += "+";
            }
            s.pop();
            ans += "-";
        }
        else
        {
            if (s.top() == x)
            {
                s.pop();
                ans += "-";
            }
            else
            {
                cout << "NO"
                     << "\n";
                return 0;
            }
        }
    }

    for (auto c : ans)
    {
        cout << c << "\n";
    }
}