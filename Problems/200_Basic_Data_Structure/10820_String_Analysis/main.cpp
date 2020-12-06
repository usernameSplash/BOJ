#include <iostream>
#include <string>
#include <algorithm>

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
    while (getline(cin, s)) // 한 줄 입력을 받으려면 cin 대신 getline을 써야한다.
    {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;

        for (auto c : s)
        {
            if ('a' <= c && c <= 'z')
                lower++;
            else if ('A' <= c && c <= 'Z')
                upper++;
            else if ('0' <= c && c <= '9')
                number++;
            else if (' ' == c)
                space++;
        }
        cout << lower << " " << upper << " " << number << " " << space << "\n";
    }

    return 0;
}