#include <cstdio>
#include <deque>

int n;
int start;
int result;

int data[100000];
bool visited[100000] = {
    false,
};

int BFS()
{
    int result = 0;
    std::deque<int> d;

    d.push_back(start);

    while (!d.empty()) {
        int cur = d.front();
        d.pop_front();

        visited[cur] = true;
        result++;

        if (0 <= (cur - data[cur]) && !visited[cur - data[cur]]) {
            d.push_back(cur - data[cur]);
        }

        if ((cur + data[cur]) < n && !visited[cur + data[cur]]) {
            d.push_back(cur + data[cur]);
        }
    }

    return result;
}

int main()
{
    int result;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }

    scanf("%d", &start);
    start--;

    result = BFS();

    printf("%d\n", result);

    return 0;
}