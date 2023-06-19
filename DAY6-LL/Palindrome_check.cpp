#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// method 1 tc-> n/2 + n/2 + n/2
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    };
    head = prev;
    return head;
}
ListNode *givemiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL)
    {
        slow = slow->next;

        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
    };
    return slow;
}
bool isPalindrome(ListNode *head)
{
    if (!head->next)
    {
        return true;
    }

    ListNode *middle = givemiddle(head);
    ListNode *reversehead = reverseList(middle);

    ListNode *curr1 = head, *curr2 = reversehead;
    while (curr1 && curr2)
    {
        if (curr1->val != curr2->val)
        {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    };

    return true;
}

int main()

{
    return 0;
}