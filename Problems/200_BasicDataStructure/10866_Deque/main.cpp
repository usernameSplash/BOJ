#include <iostream>
#include <deque>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Deque
{
    deque<int> d;

    Deque()
    {
    }

    void push_front(int n)
    {
        d.push_front(n);
    }

    void push_back(int n)
    {
        d.push_back(n);
    }

    int pop_front()
    {
        int result;
        if (d.empty())
        {
            result = -1;
        }
        else
        {
            result = d.front();
            d.pop_front();
        }
        return result;
    }

    int pop_back()
    {
        int result;
        if (d.empty())
        {
            result = -1;
        }
        else
        {
            result = d.back();
            d.pop_back();
        }
        return result;
    }

    int front()
    {
        int result;

        if (empty())
            result = -1;
        else
            result = d.front();

        return result;
    }

    int back()
    {
        int result;

        if (empty())
            result = -1;
        else
            result = d.back();

        return result;
    }

    bool empty()
    {
        return size() == 0;
    }

    int size()
    {
        return d.size();
    }
};

int main()
{
    cppIOInitialize();
    int n;
    cin >> n;

    Deque d;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push_back")
        {
            int num;
            cin >> num;
            d.push_back(num);
        }
        if (cmd == "push_front")
        {
            int num;
            cin >> num;
            d.push_front(num);
        }
        else if (cmd == "pop_back")
        {
            cout << d.pop_back() << "\n";
        }
        else if (cmd == "pop_front")
        {
            cout << d.pop_front() << "\n";
        }
        else if (cmd == "front")
        {
            cout << d.front() << "\n";
        }
        else if (cmd == "back")
        {
            cout << d.back() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << d.empty() << "\n";
        }
        else if (cmd == "size")
        {
            cout << d.size() << "\n";
        }
    }

    return 0;
}