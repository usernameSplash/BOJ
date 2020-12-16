#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int Calculate(vector<int> &data, int bitmask)
{
    int n = data.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if ((bitmask & (1 << i)))
            sum += data[i];
    }

    return sum;
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    vector<int> data(n);
    vector<bool> determinate(22000000);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for (int s = 0; s < (1 << n); s++)
    {
        int idx = Calculate(data, s);
        determinate[idx] = true;
    }

    for (int i = 1;; i++)
    {
        if (!determinate[i])
        {
            cout << i;
            break;
        }
    }

    cout << "\n";

    return 0;
}
