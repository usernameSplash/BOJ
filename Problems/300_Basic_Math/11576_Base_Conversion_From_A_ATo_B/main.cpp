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

int BaseConversionFromNto10(int num[], int b, int m)
{
    int result = 0;

    for (int i = 0; i < m; i++)
    {
        result = result * b + num[i];
    }

    return result;
}

//그냥 숫자로 하면 되는데 멍청하게 알파벳으로 변환해서 틀렸었다. 문제를 제대로 읽자.
vector<int> BaseConversionFrom10toN(int num, int b)
{
    vector<int> v;

    if(num < b) 
    {
        v.push_back(num);
        return v;
    }
    
    v = BaseConversionFrom10toN(num / b, b);
    
    int tempNum = num % b;
    v.push_back(tempNum);
    
    return v;
}

int main() 
{
    int a, b;
    cin >> a >> b;
    
    int m;
    cin >> m;

    int ABasedNumber[26];
    
    for(int i = 0; i < m; i++)
    {
        cin >> ABasedNumber[i];
    }

    int TenBasedNumber = BaseConversionFromNto10(ABasedNumber, a, m);
    
    vector<int> BBasedNumber = BaseConversionFrom10toN(TenBasedNumber, b);
    
    int i = 0;
    for(i = 0; i < BBasedNumber.size()-1; i++){
        cout << BBasedNumber[i] << " ";
    }
    cout << BBasedNumber[i];
    
    cout << "\n";

    return 0;
}
