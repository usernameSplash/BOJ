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

void Permutation(int index, int start, int n, int m)
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
        a[index] = (i + 1);
        Permutation(index + 1, i, n, m);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    Permutation(0, 0, n, m);

    cout << "\n";

    return 0;
}
