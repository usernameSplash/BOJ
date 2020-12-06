#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool checkParenthesis(string s)
{
    int temp = 0; //0으로 초기화를 안 해줘서 틀렸었다.

    for (auto c : s)
    {
        if (c == '(')
            temp++;
        else if (c == ')')
        {
            if (temp <= 0)
            {
                return false;
            }
            temp--;
        }
    }

    return temp == 0 ? true : false;
}

int main()
{
    cppIOInitialize();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string parenthesis;
        cin >> parenthesis;

        bool result = checkParenthesis(parenthesis);

        if (result)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}