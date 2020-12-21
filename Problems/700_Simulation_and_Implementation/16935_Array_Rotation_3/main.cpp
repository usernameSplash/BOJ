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

vector<vector<int>> operation1(vector<vector<int>> &d)
{
    int n = d.size();
    int m = d[0].size();

    vector<vector<int>> a(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = d[n - i - 1][j];
        }
    }

    return a;
}

vector<vector<int>> operation2(vector<vector<int>> &d)
{
    int n = d.size();
    int m = d[0].size();

    vector<vector<int>> a(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = d[i][m - j - 1];
        }
    }

    return a;
}

vector<vector<int>> operation3(vector<vector<int>> &d)
{
    int n = d.size();
    int m = d[0].size();

    vector<vector<int>> a(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = d[n - j - 1][i];
        }
    }

    return a;
}

vector<vector<int>> operation4(vector<vector<int>> &d)
{
    int n = d.size();
    int m = d[0].size();

    vector<vector<int>> a(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = d[j][m - i - 1];
        }
    }

    return a;
}

vector<vector<int>> operation5(vector<vector<int>> &d)
{
    int n = d.size();
    int m = d[0].size();

    vector<vector<int>> a(n, vector<int>(m, 0));

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            a[i][j] = d[n / 2 + i][j];
            a[i][m / 2 + j] = d[i][j];
            a[n / 2 + i][j] = d[n / 2 + i][m / 2 + j];
            a[n / 2 + i][m / 2 + j] = d[i][m / 2 + j];
        }
    }

    return a;
}

vector<vector<int>> operation6(vector<vector<int>> &d)
{
    int n = d.size();
    int m = d[0].size();

    vector<vector<int>> a(n, vector<int>(m, 0));

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            a[i][j] = d[i][m / 2 + j];
            a[i][m / 2 + j] = d[n / 2 + i][m / 2 + j];
            a[n / 2 + i][j] = d[i][j];
            a[n / 2 + i][m / 2 + j] = d[n / 2 + i][j];
        }
    }

    return a;
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> data(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> data[i][j];
        }
    }

    while (r--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            data = operation1(data);
        }
        else if (op == 2)
        {
            data = operation2(data);
        }
        else if (op == 3)
        {
            data = operation3(data);
        }
        else if (op == 4)
        {
            data = operation4(data);
        }
        else if (op == 5)
        {
            data = operation5(data);
        }
        else if (op == 6)
        {
            data = operation6(data);
        }
    }

    n = data.size();
    m = data[0].size();

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
