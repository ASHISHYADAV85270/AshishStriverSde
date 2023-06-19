#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// method 1::tc-> (m+n)logn sc==>O(N)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *ans = NULL, *curr1 = headA, *curr2 = headB;
    unordered_map<ListNode *, int> mp;
    while (curr1)
    {
        mp[curr1]++;
        curr1 = curr1->next;
    };
    while (curr2)
    {
        if (mp.find(curr2) != mp.end())
        {
            return curr2;
        }

        mp[curr2]++;
        curr2 = curr2->next;
    };
    return NULL;
}

// method2:::tc->O(m+n)+o(abs(m-n))=O(2m)  sc-> O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *curr1 = headA, *curr2 = headB;
    int a = 0, b = 0;
    while (curr1)
    {
        a++;
        curr1 = curr1->next;
    };
    while (curr2)
    {
        b++;
        curr2 = curr2->next;
    };
    curr1 = headA;
    curr2 = headB;
    // making node one as longer
    if (a < b)
    {
        swap(a, b);
        swap(curr2, curr1);
    }
    int diff = a - b;

    while (diff--)
    {
        curr1 = curr1->next;
    };

    while (curr1 && curr2)
    {
        if (curr1 == curr2)
        {
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    };
    return curr1;
}

// method 3 :::::: tc->o(2m) sc-<o(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA, *b = headB;
    while (a != b)
    {
        if (a == NULL)
        {
            a = headB;
        }
        else
        {
            a = a->next;
        }

        if (b == NULL)
        {
            b = headA;
        }
        else
        {
            b = b->next;
        }
    };
    return a;
}

int main()
{
    return 0;
}