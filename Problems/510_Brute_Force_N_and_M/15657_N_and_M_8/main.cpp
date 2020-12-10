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

int a[10] = {0};      // data
bool v[10] = {false}; // visited

void Permutation(vector<int> &data, int index, int start, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < n; i++)
    {
        a[index] = data[i];
        Permutation(data, index + 1, i, n, m);
    }
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
    sort(data.begin(), data.end());

    Permutation(data, 0, 0, n, m);

    cout << "\n";

    return 0;
}
