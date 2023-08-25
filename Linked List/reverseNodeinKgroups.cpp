

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode *reverse(ListNode *head, int i, int k)
{
    if (i == 0)
    {
        return head;
    }
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    ListNode *prev = nullptr;
    ListNode *curr = head;
    int count = 0;
    while (count < k && curr != nullptr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    head->next = reverse(curr, i - 1, k);
    return prev;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        len++;
    }
    int i = len / k;
    return reverse(head, i, k);
}