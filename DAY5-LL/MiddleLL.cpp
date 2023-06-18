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

class Solution
{
public:
    // m1-> using normal traversal tc->0(n)
    ListNode *middleNode(ListNode *head)
    {
        ListNode *curr = head;
        int ct = 0;
        while (curr)
        {
            curr = curr->next;
            ct++;
        };

        curr = head;
        ct = (ct) / 2;
        while (ct--)
        {
            curr = curr->next;
        };
        return curr;
    }

    // m2-> using fast and slow pointer tc->o(n/2)
    ListNode *middleNode(ListNode *head)
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
        }

        return slow;
    }
};

int main()
{
    return 0;
}