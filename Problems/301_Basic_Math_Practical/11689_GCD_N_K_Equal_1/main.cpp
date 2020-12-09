#include <iostream>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> getPrimeFactors(int n)
{
    vector<int> result;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            result.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        result.push_back(n);
    }

    return result;
}

int EulerPhiFunc(vector<int> v)
{
    return 0;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v = getPrimeFactors(n);

    for (auto num : v)
    {
        cout << num << "\n";
    }

    return 0;
}