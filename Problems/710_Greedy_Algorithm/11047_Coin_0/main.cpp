#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Coin(vector<int> &data, int target)
{
    int result = 0;
    for (auto d : data)
    {
        if (target >= d)
        {
            result += target / d;
            target %= d;
        }
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    reverse(data.begin(), data.end());

    cout << Coin(data, m);

    cout << "\n";

    return 0;
}
