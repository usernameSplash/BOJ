#include <array>
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
    cout << (n * (n + 1)) / 2 << "\n";
}