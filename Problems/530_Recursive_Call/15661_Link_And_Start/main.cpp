#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int result = 2000000000;

void Calculation(int l, vector<vector<int> > &data, vector<int> &t1, vector<int> &t2)
{
    int n = data.size();
    
    if(l == n)
    {
        int val1 = 0, val2 = 0;

        for (auto t : t1)
            for (auto tt : t1)
                val1 += data[t][tt];

        for (auto t : t2)
            for (auto tt : t2)
                val2 += data[t][tt];
        
        result = min(result, abs(val1 - val2));
        return ;
    }
    
    t1.push_back(l);
    Calculation(l+1, data, t1, t2);
    t1.pop_back();

    t2.push_back(l);
    Calculation(l+1, data, t1, t2);
    t2.pop_back();
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > data(n, vector<int>(n, 0));
    vector<int> order(n, 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> data[i][j];

    vector<int> t1;
    vector<int> t2;
    Calculation(0, data, t1, t2);

    cout << result << "\n";

    return 0;
}
