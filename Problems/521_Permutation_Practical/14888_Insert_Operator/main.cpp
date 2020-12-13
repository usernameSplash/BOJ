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

int Calculation(vector<int> &data, vector<int> &op)
{
    int n = op.size();
    int result = data[0];

    for (int i = 0; i < n; i++)
    {
        if (op[i] == 0)
            result += data[i + 1];
        else if (op[i] == 1)
            result -= data[i + 1];
        else if (op[i] == 2)
            result *= data[i + 1];
        else if (op[i] == 3)
            result /= data[i + 1];
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> operators;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++)
        {
            operators.push_back(i);
        }
    }

    int maxVal = -1000000000;
    int minVal = 1000000000;

    do
    {
        int temp = Calculation(nums, operators);
        maxVal = max(maxVal, temp);
        minVal = min(minVal, temp);

    } while (next_permutation(operators.begin(), operators.end()));

    cout << maxVal << "\n";
    cout << minVal << "\n";

    return 0;
}
