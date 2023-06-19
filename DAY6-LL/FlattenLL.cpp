#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//watch it from love babbar
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {

        if (left->data < right->data)
        {
            temp->bottom = left;
            temp = left;
            left = left->bottom;
        }
        else
        {
            temp->bottom = right;
            temp = right;
            right = right->bottom;
        }
    };

    while (left != NULL)
    {
        temp->bottom = left;
        temp = left;
        left = left->bottom;
    };
    while (right != NULL)
    {
        temp->bottom = right;
        temp = right;
        right = right->bottom;
    }
    ans = ans->bottom;
    return ans;
}
Node *flatten(Node *root)
{

    if (root == NULL)
    {
        return root;
    }
    Node *left = root;
    Node *right = flatten(root->next);
    left->next = NULL;

    Node *ans = merge(left, right);
    return ans;
}

int main()
{
    return 0;
}