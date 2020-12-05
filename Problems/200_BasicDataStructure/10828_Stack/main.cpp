#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Stack
{
    int size;
    int data[10000];

    Stack()
    {
        size = 0;
    }

    void push(int n)
    {
        data[size] = n;
        size++;
    }

    int pop()
    {
        int result;

        if (empty())
            result = -1;
        else
            result = data[--size];

        return result;
    }

    int top()
    {
        int result;

        if (empty())
            result = -1;
        else
            result = data[(size - 1)];

        return result;
    }

    bool empty()
    {
        return size == 0;
    }
};

int main()
{
    cppIOInitialize();
    int n;
    cin >> n;

    Stack s;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (cmd == "pop")
        {
            cout << s.pop() << "\n";
        }
        else if (cmd == "top")
        {
            cout << s.top() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << s.empty() << "\n";
        }
        else if (cmd == "size")
        {
            cout << s.size << "\n";
        }
    }
}