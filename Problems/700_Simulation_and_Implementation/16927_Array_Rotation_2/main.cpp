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

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> data(n, vector<int>(m, 0));
    vector<vector<int>> groups;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> data[i][j];
        }
    }

    int mid = min(n, m) / 2;

    for (int k = 0; k < mid; k++)
    {
        vector<int> group;
        for (int j = k; j < m - k; j++)
        {
            group.push_back(data[k][j]);
        }

        for (int i = k + 1; i < n - k - 1; i++)
        {
            group.push_back(data[i][m - k - 1]);
        }

        for (int j = m - k - 1; j > k; j--)
        {
            group.push_back(data[n - k - 1][j]);
        }

        for (int i = n - k - 1; i > k; i--)
        {
            group.push_back(data[i][k]);
        }
        groups.push_back(group);
    }

    for (int k = 0; k < mid; k++)
    {
        vector<int> &group = groups[k];
        int len = group.size();
        int index = r % len;

        for (int j = k; j < m - k; j++)
        {
            data[k][j] = group[index];
            index = (index + 1) % len;
        }

        for (int i = k + 1; i < n - k - 1; i++)
        {
            data[i][m - k - 1] = group[index];
            index = (index + 1) % len;
        }

        for (int j = m - k - 1; j > k; j--)
        {
            data[n - k - 1][j] = group[index];
            index = (index + 1) % len;
        }

        for (int i = n - k - 1; i > k; i--)
        {
            data[i][k] = group[index];
            index = (index + 1) % len;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
