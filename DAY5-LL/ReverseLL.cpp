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
};

int main()
{
    return 0;
}