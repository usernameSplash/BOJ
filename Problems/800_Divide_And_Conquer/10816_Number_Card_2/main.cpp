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

int lowerBound(vector<int> &data, int target, int start, int end)
{
    if (start >= end)
        return start;

    int mid = (start + end) / 2;

    if (target <= data[mid])
        return lowerBound(data, target, start, mid);
    else
        return lowerBound(data, target, mid + 1, end);
}

int upperBound(vector<int> &data, int target, int start, int end)
{
    if (start >= end)
        return start;

    int mid = (start + end) / 2;

    if (target >= data[mid])
        return upperBound(data, target, mid + 1, end);
    else
        return upperBound(data, target, start, mid);
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
        int l = lowerBound(data, c, 0, n);
        int u = upperBound(data, c, 0, n);
        cout << u - l << " ";
    }
    cout << "\n";

    return 0;
}