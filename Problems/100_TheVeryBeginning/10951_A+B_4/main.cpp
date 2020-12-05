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

    while (true)
    {
        int a, b;
        cin >> a >> b;

        if (cin.eof())
            break;

        cout << (a + b) << endl;
    }
}