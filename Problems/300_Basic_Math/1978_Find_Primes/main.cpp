#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool isPrime(int n)
{
    if (n < 2) 
        return false;

    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    int answer = 0;
    while(T--)
    {
        int num;
        cin >> num;
        if(isPrime(num))
            answer++;
    }
    cout << answer;
    cout << "\n";

    return 0;
}