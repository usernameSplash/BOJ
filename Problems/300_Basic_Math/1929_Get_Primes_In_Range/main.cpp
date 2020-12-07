#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void eratosthenes(bool (&seive)[1000000])
{
    for(int i = 2; i <= 1000000; i++)
    {
        if(!seive[i])
        {
            for(int j = i*2; j <= 1000000; j += i)
            {
                seive[j] = true;
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    bool seive[1000000] = {false};
    seive[0] = true;
    seive[1] = true;

    eratosthenes(seive);

    for(int i = m; i <= n; i++)
    {
        if(!seive[i])
        {
            cout << i << "\n";
        }
    }

    return 0;
}