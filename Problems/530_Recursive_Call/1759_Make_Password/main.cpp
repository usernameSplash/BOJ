#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool CheckPassword(const string &p)
{
    int vowels = 0;
    int consonants = 0;
    for (auto c : p)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowels++;
        else
            consonants++;

        if (vowels >= 1 && consonants >= 2)
            return true;
    }
    return false;
}

void MakePassword(int l, vector<char> &pwd, string p, int i)
{
    if (l == p.length())
    {
        if (CheckPassword(p))
            cout << p << "\n";
        return;
    }
    else if (i >= pwd.size())
    {
        return;
    }

    MakePassword(l, pwd, p + pwd[i], i + 1);
    MakePassword(l, pwd, p, i + 1);
}

int main()
{
    int l, c;
    cin >> l >> c;

    vector<char> pwd(c);
    for (int i = 0; i < c; i++)
    {
        cin >> pwd[i];
    }
    sort(pwd.begin(), pwd.end());

    MakePassword(l, pwd, "", 0);

    return 0;
}
