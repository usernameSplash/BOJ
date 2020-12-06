#include <iostream>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Queue
{
    int _begin;
    int _end;
    int data[10001];

    Queue()
    {
        _begin = 0;
        _end = 0;
    }

    void push(int n)
    {
        data[_end] = n;
        _end++;
    }

    int pop()
    {
        int result;

        if (empty())
        {
            result = -1;
        }
        else
        {
            result = data[_begin];
            _begin++;
        }

        return result;
    }

    int front()
    {
        int result;

        if (empty())
            result = -1;
        else
            result = data[_begin];

        return result;
    }

    int back()
    {
        int result;

        if (empty())
            result = -1;
        else
            result = data[(_end - 1)];

        return result;
    }

    bool empty()
    {
        return size() == 0;
    }

    int size()
    {
        return (_end - _begin);
    }
};

int main()
{
    cppIOInitialize();
    int n;
    cin >> n;

    Queue q;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop")
        {
            cout << q.pop() << "\n";
        }
        else if (cmd == "front")
        {
            cout << q.front() << "\n";
        }
        else if (cmd == "back")
        {
            cout << q.back() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << q.empty() << "\n";
        }
        else if (cmd == "size")
        {
            cout << q.size() << "\n";
        }
    }

    return 0;
}