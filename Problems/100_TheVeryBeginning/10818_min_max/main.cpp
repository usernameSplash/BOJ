#include <array>
#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    cppIOInitialize();
    int n, min = 1000000, max = -1000000;
    cin >> n;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (min > temp)
            min = temp;
        if (max < temp)
            max = temp;
    }
    cout << min << " " << max << "\n";
}