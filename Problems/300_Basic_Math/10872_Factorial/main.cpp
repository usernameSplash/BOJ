#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Factorial(int n)
{
    if(n == 0) 
        return 1;
    
    return n * Factorial(n - 1);
}


int main()
{
    int n;
    cin >> n;

    cout << Factorial(n);
    cout << "\n";

    return 0;
}