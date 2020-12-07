#include <iostream>

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
    getline(cin, s);

    for (auto c : s)
    {
        if ('A' <= c and c <= 'A' + 12)
        {
            cout << static_cast<char>(c + 13);
        }
        else if ('A' + 13 <= c and c <= 'Z')
        {
            cout << static_cast<char>(c - 13);
        }
        else if ('a' <= c and c <= 'a' + 12)
        {
            cout << static_cast<char>(c + 13);
        }
        else if ('a' + 13 <= c and c <= 'z')
        {
            cout << static_cast<char>(c - 13);
        }
        else
        {
            cout << c;
        }
    }

    cout << "\n";

    return 0;
}