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
};

void preOrder(int root, vector<Node> &tree)
{
    if(root == -1)
        return;

    cout << static_cast<char>(root + 'A');
    preOrder(tree[root].left, tree);
    preOrder(tree[root].right, tree);
}

void inOrder(int root, vector<Node> &tree)
{
    if(root == -1)
        return;
    
    inOrder(tree[root].left, tree);
    cout << static_cast<char>(root + 'A');
    inOrder(tree[root].right, tree);
}

void postOrder(int root, vector<Node> &tree)
{
    if(root == -1)
        return;
    
    postOrder(tree[root].left, tree);
    postOrder(tree[root].right, tree);
    cout << static_cast<char>(root + 'A');
}

int main()
{
    cppIOInitialize();

    int n;
    cin >> n;

    vector<Node> tree(n);

    for(int i = 0; i < n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;

        a = a - 'A';

        tree[a].left = (b != '.') ? b - 'A' : -1;
        tree[a].right = (c != '.') ? c - 'A' : -1;
    }

    preOrder(0, tree);
    cout << "\n";

    inOrder(0, tree);
    cout << "\n";

    postOrder(0, tree);
    cout << "\n";

    return 0;
}