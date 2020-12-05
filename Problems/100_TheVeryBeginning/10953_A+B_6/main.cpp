#include <cstdio>

using namespace std;

// void cppIOInitialize()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
// }

int main()
{
    // cppIOInitialize();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d,%d", &a, &b);

        printf("%d\n", a + b);
    }
}