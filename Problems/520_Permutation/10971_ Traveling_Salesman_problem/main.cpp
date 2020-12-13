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

int calculation(vector<vector<int>> &data, vector<int> &order)
{
    int result = 0;
    int n = data.size();
    int o = order[0];
    int _o = order[1];

    for (int i = 0; i < n - 1; i++)
    {
        o = order[i];
        _o = order[i + 1];

        if (data[o][_o] == 0)
            return -1;
        result += data[o][_o];
    }

    if (data[_o][order[0]] != 0)
        result += data[_o][order[0]];
    else
        return -1;

    return result;
}

int solve(vector<vector<int>> &data)
{
    int result = 1e9;
    int temp = 0;
    int n = data.size();

    vector<int> order(n);
    for (int i = 0; i < n; i++)
    {
        order[i] = i;
    }

    do
    {
        temp = calculation(data, order);
        if (temp > 0 && temp < result)
            result = temp;

    } while (next_permutation(order.begin(), order.end()));

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> data(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> data[i][j];
        }
    }

    cout << solve(data);

    cout << "\n";

    return 0;
}
