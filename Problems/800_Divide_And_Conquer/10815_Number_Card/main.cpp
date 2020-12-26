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

bool binarySearch(vector<int> &data, int target, int start, int end)
{
    if (start > end)
        return false;

    int mid = (start + end) / 2;

    if (data[mid] == target)
        return true;
    else if (data[mid] < target)
        return binarySearch(data, target, mid + 1, end);
    else if (data[mid] > target)
        return binarySearch(data, target, start, mid - 1);
}

int main()
{
    cppIOInitialize();

    int n, m;
    cin >> n;
    vector<int> data(n);

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    cin >> m;
    vector<int> card(m);

    for (int i = 0; i < m; i++)
    {
        cin >> card[i];
    }

    sort(data.begin(), data.end());

    for (auto c : card)
    {
        if (binarySearch(data, c, 0, n - 1))
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    cout << "\n";

    return 0;
}