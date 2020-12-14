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
    
    int n;
    cin >> n;

    int set = 0;

    string cmd;
    int num;

    while(n--)
    {
        cin >> cmd;
        
        if(cmd == "empty")
            set = 0;
        else if(cmd == "all")
            set = ((1 << 20) - 1); // 이진수 11111111111111111111
        else if(cmd == "add")
        {
            cin >> num;
            num--;
            set |= (1 << num);
        }
        else if(cmd == "remove")
        {
            cin >> num;
            num--;
            set &= ~(1 << num);
        }
        else if(cmd == "toggle")
        {
            cin >> num;
            num--;
            set ^= (1 << num);
        }
        else if(cmd == "check")
        {
            cin >> num;
            num--;
            int result = (set & (1 << num)) == 0 ? 0 : 1;
            cout << result << "\n";
        }

    }
    cout << "\n";

    return 0;
}
