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
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++)
    {
        cout << n << " * " << i << " = " << n * i << "\n";
    }
}