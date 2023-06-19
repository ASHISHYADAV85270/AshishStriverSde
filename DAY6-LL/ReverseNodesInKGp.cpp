#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// love babbar
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    int lenghtofLL(ListNode *head)
    {
        int ct = 0;
        ListNode *curr = head;
        while (curr)
        {
            ct++;
            curr = curr->next;
        };
        return ct;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = lenghtofLL(head);
        if (head == NULL || len < k)
        {
            return head;
        }
        int ct = k;
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (ct-- && curr != NULL)
        {
            ListNode *next_ele = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_ele;
        };

        // prev is the new head
        // head is the new tail
        // curr is the next recursion starting head
        if (curr != NULL)
        {
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }
};
int main()
{
    return 0;
}