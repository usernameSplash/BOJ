#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void eratosthenes(bool (&sieve)[1000000])
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (!sieve[i])
        {
            for (int j = i * 2; j <= 1000000; j += i)
            {
                sieve[j] = true;
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    bool sieve[1000000] = {false};
    sieve[0] = true;
    sieve[1] = true;

    eratosthenes(sieve);

    for (int i = m; i <= n; i++)
    {
        if (!sieve[i])
        {
            cout << i << "\n";
        }
    }

    return 0;
}