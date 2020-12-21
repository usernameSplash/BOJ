#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cppIOInitialize()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct Node{
    int left;
    int right;
    int width;
    int depth;
};

int order = 1;
void inOrder(int root, vector<Node> &tree, int depth)
{
    if(root == -1)
        return;
    
    inOrder(tree[root].left, tree, depth + 1);
    
    tree[root].depth = depth;
    tree[root].width = order;
    order++;
    
    inOrder(tree[root].right, tree, depth + 1);
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    vector<Node> tree(10001);
    vector<int> cnt(10001, 0);
    vector<int> left(10001, 0);
    vector<int> right(10001, 0);

    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(b != -1)
            cnt[b]++;
        tree[a].left = b;

        if(c != -1)
            cnt[c]++;
        tree[a].right = c;
    }

    int root = 0;

    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == 0)
        {
            root = i;
            break;
        }
    }


    inOrder(root, tree, 1);
    

    int maxDepth = 0;

    for(int i = 1; i <= n; i++)
    {
        int w = tree[i].width;
        int d = tree[i].depth;

        if(left[d] != 0)
        {
            left[d] = min(left[d], w);
        }
        else
        {
            left[d] = w;
        }

        right[d] = max(right[d], w);

        maxDepth = max(maxDepth, d);
    }

    int ans = 0;
    int ansDepth = 0;

    for(int i = 1; i <= maxDepth; i++)
    {
        if(ans < (right[i] - left[i]) + 1)
        {
            ans = (right[i] - left[i]) + 1;
            ansDepth = i;
        }
    }

    cout << ansDepth << " " << ans;
    
    cout << "\n";


    return 0;
}