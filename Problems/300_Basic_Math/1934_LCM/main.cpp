#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int GCD(int a, int b) 
{
    if(a < b) 
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if(a % b == 0) {
        return b;
    }

    return GCD(b, a%b);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main() 
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cout << LCM(a, b) << "\n";
    }

    return 0;
}