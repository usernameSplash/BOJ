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

bool NextPermutation(vector<int> &data)
{
    int n = data.size();
    int leftIdx = -1;
    int rightIdx = -1;

    for (int i = n - 1; i > 0; i--)
    {
        if (data[i - 1] < data[i])
        {
            leftIdx = i;
            break;
        }
    }

    if (leftIdx == -1)
    {
        return false;
    }

    for (int j = n - 1; j >= leftIdx; j--)
    {
        if (data[leftIdx - 1] < data[j])
        {
            swap(data[leftIdx - 1], data[j]);
            break;
        }
    }

    rightIdx = n - 1;
    while (leftIdx < rightIdx)
    {
        swap(data[leftIdx], data[rightIdx]);
        leftIdx++;
        rightIdx--;
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

    if (NextPermutation(data))
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
