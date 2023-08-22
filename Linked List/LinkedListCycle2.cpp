
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    if (head->next == head)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr)
    {
        if (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast = fast->next;
        if (fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
