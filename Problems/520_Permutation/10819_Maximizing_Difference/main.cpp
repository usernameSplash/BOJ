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

int calculation(vector<int> &data)
{
    int result = 0;
    int n = data.size();

    for (int i = 1; i < n; i++)
    {
        result += abs(data[i - 1] - data[i]);
    }

    return result;
}

int solve(vector<int> &data)
{
    int result = 0;

    do
    {
        result = max(result, calculation(data));
    } while (next_permutation(data.begin(), data.end()));

    return result;
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

    sort(data.begin(), data.end());

    cout << solve(data);

    cout << "\n";

    return 0;
}
