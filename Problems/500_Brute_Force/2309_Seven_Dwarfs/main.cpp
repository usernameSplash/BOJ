#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    const int NUM_OF_DWARFS = 9;

    vector<int> data(NUM_OF_DWARFS);

    int sum = 0;
    for(int i = 0; i < NUM_OF_DWARFS; i++)
    {
        cin >> data[i];
        sum += data[i];
    }
    sort(data.begin(), data.end());

    for(int i = 0; i < NUM_OF_DWARFS; i++)
    {
        for(int j = i + 1; j < NUM_OF_DWARFS; j++)
        {
            if(sum - data[i] - data[j] == 100)
            {
                for(int k = 0; k < NUM_OF_DWARFS; k++)
                {
                    if(k == i || k == j) 
                        continue;
                    cout << data[k] << "\n";
                }
                return 0;
            }
        }
    }

    return 0;
}