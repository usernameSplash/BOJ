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

bool InequalSign(vector<char> &data, vector<int> &v)
{
    int n = data.size();
    for (int i = 0; i < n; i++)
    {
        if (data[i] == '<')
        {
            if (v[i] > v[i + 1])
                return false;
        }
        else
        {
            if (v[i] < v[i + 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<char> data(n);
    vector<int> maxVector(n + 1);
    vector<int> minVector(n + 1);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    for (int i = 0; i <= n; i++)
    {
        maxVector[i] = (9 - i);
        minVector[i] = i;
    }

    while (!InequalSign(data, maxVector))
    {
        prev_permutation(maxVector.begin(), maxVector.end());
    }

    while (!InequalSign(data, minVector))
    {
        next_permutation(minVector.begin(), minVector.end());
    }

    for (auto v : maxVector)
        cout << v;

    cout << "\n";

    for (auto v : minVector)
        cout << v;

    cout << "\n";

    return 0;
}
