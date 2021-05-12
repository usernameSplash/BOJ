#include <iostream>
#include <vector>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(int n, int from, int to)
{
    if (n == 0)
        return;

    // 6 - from - to 는 from도 to도 아닌 제 3의 기둥을 의미한다.
    // 기둥의 각 번호는 1, 2, 3이므로 1+2+3 = 6이기 때문에 6에서 from과 to를 뺀다.

    solve(n - 1, from, 6 - from - to);
    cout << from << " " << to << "\n";
    solve(n - 1, 6 - from - to, to);
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";

    solve(n, 1, 3);
    return 0;
}