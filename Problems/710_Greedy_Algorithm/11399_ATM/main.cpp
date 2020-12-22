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

int solve(vector<int> &d)
{
    int result = 0;
    int n = d.size();

    for (int i = 0; i < n; i++)
    {
        result += d[i] * (n - i);
    }
    
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
    
    int result = solve(data);

    cout << result;

    cout << "\n";

    return 0;
}
