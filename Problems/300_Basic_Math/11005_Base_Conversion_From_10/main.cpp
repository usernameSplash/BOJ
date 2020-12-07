#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

char GetNumberWithOtherBase(int n) //임의의 진법체계에 대해 숫자를 반환하는 함수. 10 이상 35이하의 수는 A~Z로 표기한다.
{
    if(0 <= n && n < 10) 
    {
        return '0' + n;
    }
    else {
        return 'A' + (n-10);
    }
}

void BaseConversion(int n, int b)
{
    if(n < b) 
    {
        cout << GetNumberWithOtherBase(n);
        return;
    }
    BaseConversion(n / b, b);
    cout << GetNumberWithOtherBase(n % b);
}

int main() 
{
    int n, b;
    cin >> n >> b;

    BaseConversion(n, b);
    cout << "\n";

    return 0;
}