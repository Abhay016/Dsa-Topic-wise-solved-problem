
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse(ListNode *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *temp = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *newhead = reverse(head);
    return newhead;
}
