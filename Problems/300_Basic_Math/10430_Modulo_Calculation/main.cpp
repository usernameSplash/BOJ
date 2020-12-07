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
    int a, b, c;
    cin >> a >> b >> c;

    cout << (a+b) % c << "\n";
    cout << (a+b) % c << "\n";
    cout << (a*b) % c << "\n";
    cout << (a*b) % c << "\n";

    return 0;
}