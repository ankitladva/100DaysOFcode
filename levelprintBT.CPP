//today i wrote efficient code for max element in binary tree,leftview with time complexity O(n).
//and also from iterative method. 
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
void printlevel(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    while (q.empty() == 0)
    {
        node *curr = q.front();
        cout << curr->key << " ";
        q.pop();
        if (curr->left != 0)
            q.push(curr->left);

        if (curr->right != 0)
            q.push(curr->right);
    }
} 
int maxlevel = 0;

void printlview(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (maxlevel < level)
    {
        cout << root->key << " ";
        maxlevel = level;
    }
    printlview(root->left, level + 1);
    printlview(root->right, level + 1);
}
void printleft(node *root)
{
    printlview(root, 1);
}

void printleftviewiterativemeth(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
} 
int main()
{
    node *root = new node(10);
    root->left = new node(30);
    root->left->left = new node(20);
    root->left->left->left = new node(200);

    root->right = new node(40);
    root->right->right = new node(80);
    printlevel(root);
     


    return 0;
}