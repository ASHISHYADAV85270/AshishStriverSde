#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// m1=> tc->o(n) sc->o(n)
bool hasCycle(ListNode *head)
{
    ListNode *curr = head;
    unordered_map<ListNode *, int> mp;

    while (curr)
    {
        if (mp.find(curr) != mp.end())
        {
            return true;
        }

        mp[curr]++;
        curr = curr->next;
    };
    return false;
}
// m2=>tc->n  sc->o(1 )
bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && slow)
    {

        slow = slow->next;
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    return 0;
}