#include <iostream>
#include <stack>

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

    stack<char> left_stack;
    stack<char> right_stack;

    string sentence;
    cin >> sentence;

    for (auto c : sentence)
    {
        left_stack.push(c);
    }

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "P")
        {
            char character;
            cin >> character;
            left_stack.push(character);
        }
        else if (cmd == "L")
        {
            if (left_stack.size() > 0)
            {
                right_stack.push(left_stack.top());
                left_stack.pop();
            }
        }
        else if (cmd == "D")
        {
            if (right_stack.size() > 0)
            {
                left_stack.push(right_stack.top());
                right_stack.pop();
            }
        }
        else if (cmd == "B")
        {
            if (left_stack.size() > 0)
            {
                left_stack.pop();
            }
        }
    }

    while (left_stack.size() > 0)
    {
        right_stack.push(left_stack.top());
        left_stack.pop();
    }

    while (right_stack.size() > 0)
    {
        cout << right_stack.top();
        right_stack.pop();
    }

    cout << "\n";

    return 0;
}