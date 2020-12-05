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
    int m, d, delta_m, delta_d, result;
    cin >> m >> d;

    delta_m = m - 1;
    delta_d = d - 1;

    const array<int, 12> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const array<string, 7> dates = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    for (int i = 0; i < delta_m; i++)
    {
        delta_d += days[i];
    }
    result = delta_d % 7;

    cout << dates[result] << endl;
}