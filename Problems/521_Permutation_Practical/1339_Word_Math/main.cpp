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

bool cmp(int a, int b)
{
    return a > b;
}

int wordMath()
{
    return 0;
}

int main()
{
    int n, sum = 0;
    cin >> n;

    vector<int> wordData(26, 0);

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;

        int k = s.size();
        for (int i = 0; i < k; i++)
        {
            char c = s[i];
            int idx = c - 'A';
            wordData[idx] += pow(10, k - i - 1);
        }
    }

    sort(wordData.begin(), wordData.end(), cmp);

    int num = 9;
    for (auto w : wordData)
    {
        if (w == 0)
        {
            break;
        }
        sum += w * num;
        num--;
    }
    cout << sum << "\n";

    return 0;
}
