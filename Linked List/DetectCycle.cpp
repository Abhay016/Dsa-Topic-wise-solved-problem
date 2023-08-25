
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }
    if (head->next == head)
    {
        return true;
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
            return true;
        }
    }
    return false;
}
