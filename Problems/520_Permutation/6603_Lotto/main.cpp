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

void printLotto(vector<int> &data)
{
    int result = 1e9;
    int temp = 0;
    int n = data.size();

    vector<int> order(n, 1);

    vector<vector<int>> answer;

    for (int i = 0; i < n - 6; i++)
    {
        order[i] = 0;
    }

    do
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (order[i] == 1)
                temp.push_back(data[i]);
        }
        answer.push_back(temp);

    } while (next_permutation(order.begin(), order.end()));

    sort(answer.begin(), answer.end());

    for (auto a : answer)
    {
        for (auto v : a)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    return;
}

int main()
{
    while (true)
    {
        int k = 0;
        cin >> k;

        if (k == 0)
            break;

        vector<int> data(k);

        for (int i = 0; i < k; i++)
            cin >> data[i];

        printLotto(data);
    }

    return 0;
}
