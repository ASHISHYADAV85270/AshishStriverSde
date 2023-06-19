#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head, *fast = head;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
            if (fast == slow)
            {
                break;
            }
        };
        if (fast == NULL)
        {
            return fast;
        }
        fast = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        };
        return fast;
    }
};
int main()

{
    return 0;
}