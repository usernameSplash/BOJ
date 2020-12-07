#include <iostream>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int pow(int base, int exp) 
{
    int res = 1;
    while (exp)
    {
        if (exp & 1)
            res *= base;
        exp >>= 1;
        base *= base;
    }
    return res;
}

int GetNumberWith10Base(char n) //임의의 진법체계의 숫자를 10진법의 숫자로 변환하여 반환하는 함수. A~Z로 표기된 10 이상 35이하의 수를 반환한다.
{
    if('0' <= n && n <= '9')  // 여기서 "n < 9" 라는 바보같은 실수로 인해 오답이 나왔었다. (잃어버린 2시간..)
    {
        return n - '0';
    }
    else
    {
        return n - 'A' + 10;
    }
}


void BaseConversion(string n, int b)
{
    int result = 0;
    int i = 0;
    for (int i = 0; i < n.size(); i++)
    {
        int tempNum = GetNumberWith10Base(n[i]);
        result = result * b + tempNum;
        
        // result += tempNum * pow(b, (length-i-1));
        // result = result + (tempNum * pow(b, length-i-1));
    }
    
    cout << result;
}

int main() 
{
    string n;
    int b;
    cin >> n >> b;

    BaseConversion(n, b);
    cout << "\n";

    return 0;
}