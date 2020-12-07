#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/*
    for문의 반복자를 long long 자료형으로 선언해야
    BOJ에서 런타임 오류가 발생하지 않는다.
    (n, m의 최댓값이 20억이다. i *= 5등의 연산에서 에러가 발생한다.)
*/

long long getNumOfFiveInFactorial(long long n)
{
    long long result = 0;

    for (long long i = 5; i <= n; i *= 5)
    {
        result += n / i;
    }

    return result;
}

long long getNumOfTwoInFactorial(long long n)
{
    long long result = 0;

    for (long long i = 2; i <= n; i *= 2)
    {
        result += n / i;
    }

    return result;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    long long fives = getNumOfFiveInFactorial(n) - getNumOfFiveInFactorial(m) - getNumOfFiveInFactorial(n - m);
    long long twos = getNumOfTwoInFactorial(n) - getNumOfTwoInFactorial(m) - getNumOfTwoInFactorial(n - m);

    if (fives < twos)
        cout << fives;
    else
        cout << twos;

    cout << "\n";

    return 0;
}