#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//곱해서 맨 뒷 자릿수가 0이 만들어지는 경우는 2와 5가 곱해지는 경우뿐이다.
//유한한 음이 아닌 정수집합에서 2의 배수는 항상 5의 배수보다 많으므로
//n!의 소인수들 중 5가 몇 개 들어있는지 알아내면 된다.
int getNumOfZerosInFactorial(int n)
{
    int result = 0;

    for (int i = 5; i <= n; i *= 5)
    {
        result += n / i;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    cout << getNumOfZerosInFactorial(n) << "\n";

    return 0;
}