#include <iostream>
#include <map>
#include <cmath>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

long long EulerPhiFunc(long long n)
{
    double result = n;

    for (long long i = 2; i * i <= n; i++)
    {
        int exp = 0;
        if(n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            result *= (1.0 - (1.0 / double(i)));
        }
    }

    if (n > 1)
    {
        result *= (1.0 - (1.0 / double(n)));
    }

    return (long long) result;
}

// int EulerPhiFunc(map<long long, int> m) // 시간 초과가 난다.
// {
//     long result = 1;
//     for(auto factors : m)
//     {
//         int base = factors.first;
//         int exp = factors.second;
//         result *= (powl(base, exp) - powl(base, exp-1)); // 실수 연산을 하면 오차가 있을 수 있어서 이 공식을 따른다.
//     }

//     return result;
// }

int main()
{
    long long n;
    cin >> n;

    long long answer = EulerPhiFunc(n);

    cout << answer;
    cout << "\n";

    return 0;
}