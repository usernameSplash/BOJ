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

void Permutation(int index, int n, int m)
{
    if (index == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            v[i] = true;
            a[index] = (i + 1);
            Permutation(index + 1, n, m);
            v[i] = false;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    Permutation(0, n, m);

    cout << "\n";

    return 0;
}
