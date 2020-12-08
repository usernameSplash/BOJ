#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

stack<int> LIS(int data[], int n)
{
    int result = 0; // 수열의 길이를 나타낸다.

    stack<int> s;  // 수열의 항들을 저장하기 위한 스택이다. 마지막에서부터 거꾸로 들어가게 되므로 스택을 사용한다.

    int dp[1001] = {0};
    int indexes[1001] = {0};

    dp[0] = 1;
    indexes[0] = -1;
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1;
        int tempIndex = -1; // dp 테이블이 갱신될 때의 data를 저장하기 위한 임시 인덱스이다.

        for(int j = 0; j < i; j++)
        {
            if(data[i] > data[j]) 
            {
                if(dp[i] < dp[j] + 1)
                {
                    tempIndex = j;
                    dp[i] = dp[j] + 1;
                }
            }
            indexes[i] = tempIndex;
        }
    }
    
    int tempIndex = 0;
    for(int i = 0; i < n; i++)
    {
        if(result < dp[i])
        {
            tempIndex = i;
            result = dp[i];
        }
    }

    while (tempIndex != -1)
    {
        s.push(data[tempIndex]);
        tempIndex = indexes[tempIndex];
    }
    

    return s;
}

int main()
{
    int n;
    int data[1001];
    
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    stack<int> answer = LIS(data, n);

    cout << answer.size() << "\n";

    while(!answer.empty())
    {
        cout << answer.top() << " ";
        answer.pop();
    }

    cout << "\n";

    return 0;
}