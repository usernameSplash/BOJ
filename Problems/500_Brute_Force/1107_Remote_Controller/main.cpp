#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(int n, vector<int> &btn)
{
    while (true)
    {
        int temp = n % 10;
        for (auto b : btn)
        {
            if (temp == b)
            {
                return false;
            }
        }
        n /= 10;

        if (n == 0)
            break;
    }
    return true;
}

int RemoteControll(int target, vector<int> &btn)
{
    int answer = abs(target - 100); // 숫자 버튼을 한 번도 안 누르는 경우이다.
    if (check(0, btn))
        answer = min(answer, target + 1); // 0에서 이동하는 경우를 미리 처리했다. 아래의 로그 함수에서 오류가 나기 때문.

    for (int i = 1; i <= 1000000; i++)
    {
        if (check(i, btn))
        {
            int numButtons = static_cast<int>(log10l(i));
            int upDownButtons = abs(target - i) + 1;
            int answerCandidate = numButtons + upDownButtons;

            if (answer > answerCandidate)
                answer = answerCandidate;
        }
    }

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> broken_buttons(m);

    for (int i = 0; i < m; i++)
    {
        cin >> broken_buttons[i];
    }

    int ans = RemoteControll(n, broken_buttons);

    cout << ans;

    cout << "\n";

    return 0;
}
