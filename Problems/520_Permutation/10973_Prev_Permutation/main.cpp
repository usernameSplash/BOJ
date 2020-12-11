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

bool PrevPermutation(vector<int> &data)
{
    int n = data.size();

    int i = n - 1;
    while (i > 0 && data[i - 1] < data[i])
        i--;

    if (i <= 0)
        return false;

    int j = n - 1;
    while (j >= i && data[i - 1] < data[j])
        j--;

    swap(data[i - 1], data[j]);

    j = n - 1;
    while (i < j)
    {
        swap(data[i], data[j]);
        i++;
        j--;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    if (PrevPermutation(data))
    {
        for (auto d : data)
        {
            cout << d << " ";
        }
    }
    else
    {
        cout << -1;
    }

    cout << "\n";

    return 0;
}
