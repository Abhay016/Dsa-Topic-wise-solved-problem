
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    count = count / 2;
    while (count--)
    {
        head = head->next;
    }
    return head;
}
