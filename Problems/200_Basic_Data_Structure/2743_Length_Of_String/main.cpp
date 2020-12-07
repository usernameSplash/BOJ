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
    cin >> s;

    int result = 0;
    for (int i = 0; s[i]; i++) //문자열의 맨 끝 문자는 NULL임을 이용한 방법이다.
    {
        result++;
    }

    cout << result << "\n";

    return 0;
}