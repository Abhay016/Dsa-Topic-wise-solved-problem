
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *prev = head;
    ListNode *curr = head->next;
    while (curr != nullptr)
    {
        if (prev->val == curr->val)
        {
            ListNode *temp = curr->next;
            prev->next = temp;
            curr->next = nullptr;
            curr = temp;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}