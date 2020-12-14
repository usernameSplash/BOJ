#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int data[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &data[i][j]);
        }
    }

    int s = 0; // 비트마스킹 변수
    int max_val = 1 << (n * m);

    int result = 0;

    for (s = 0; s < max_val; s++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < m; j++)
            {
                int k = i * m + j;
                if ((s & (1 << k)) == 0)
                {
                    cur = cur * 10 + data[i][j];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for (int j = 0; j < m; j++)
        {
            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                int k = i * m + j;
                if ((s & (1 << k)) > 0)
                {
                    cur = cur * 10 + data[i][j];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        result = max(result, sum);
    }

    printf("%d\n", result);
}