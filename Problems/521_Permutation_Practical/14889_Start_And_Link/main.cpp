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

int Calculation(vector<vector<int>> &data, vector<int> &order)
{
    int n = data.size();
    int val1 = 0, val2 = 0;
    vector<int> t1;
    vector<int> t2;

    for (int i = 0; i < n; i++)
    {
        if (order[i] == 0)
            t1.push_back(i);
        else
            t2.push_back(i);
    }

    for (auto t : t1)
        for (auto tt : t1)
            val1 += data[t][tt];

    for (auto t : t2)
        for (auto tt : t2)
            val2 += data[t][tt];

    return abs(val1 - val2);
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> data(n, vector<int>(n, 0));
    vector<int> order(n, 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> data[i][j];

    for (int i = 0; i < n / 2; i++)
    {
        order[i] = 0;
    }

    int result = 2000000000;
    do
    {
        result = min(result, Calculation(data, order));
    } while (next_permutation(order.begin(), order.end()));

    cout << result << "\n";

    return 0;
}
