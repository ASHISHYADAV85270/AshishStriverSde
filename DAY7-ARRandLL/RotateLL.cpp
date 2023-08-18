#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *rotateRight(ListNode *head, int k)
{

    if (head == NULL || head->next == NULL)

        return head;
    int len = 0;
    ListNode *curr = head, *tail;

    while (curr != NULL)
    {
        len++;
        tail = curr;
        curr = curr->next;
    };
    k = k % len;
    int y = len - k;

    curr = head;
    ListNode *prev = curr;
    while (y--)
    {
        prev = curr;
        curr = curr->next;
    };

    tail->next = head;
    head = prev->next;
    prev->next = NULL;

    return head;
}
int main()
{
    return 0;
}