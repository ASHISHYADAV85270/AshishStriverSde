
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

// m1-> tc-> n+O(n-r)  sc->o(1)
ListNode *removeNthFromEnd(ListNode *head, int n)
{

    int ct = 0;
    ListNode *curr = head;
    while (curr)
    {
        ct++;
        curr = curr->next;
    };
    if (n == ct)
    {
        head = head->next;
        return head;
    }

    curr = head;
    ListNode *prev = NULL;
    int node_to_be_del = ct - n;

    while (node_to_be_del--)
    {
        prev = curr;
        curr = curr->next;
    };

    prev->next = prev->next->next;
    return head;
}

// m2-> if u are allowed to traverse only one i.e. tc->o(n)
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;
    while (n--)
    {
        fast = fast->next;
    };

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    };
    slow->next = slow->next->next;
    return dummy->next;
}
int main()
{
    return 0;
}