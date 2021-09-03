//today i wrote efficient code for max element in binary tree,leftview with time complexity O(n).
#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
int maxele(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->key;
    }

    return max(maxele(root->left), maxele(root->right));
}

int main()
{
    node *root = new node(10);
    root->left = new node(30);
    root->left->left = new node(20);
    root->left->left->left = new node(200);

    root->right = new node(40);
    root->right->right = new node(80);

    cout << maxele(root) << endl;

    return 0;
}