
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void insertAtBottom(stack<int> &s, int top)
{
    if (s.empty())
    {
        s.push(top);
        return;
    }
    int t = s.top();
    s.pop();
    insertAtBottom(s, top);
    s.push(t);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
}

void Reverse(stack<int> &St)
{
    reverseStack(St);
}

int main()
{
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    stack<int> temp(s);
    cout<<"Before reversing: "<<endl;
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    Reverse(s);
    cout<<endl<<"After reversing: "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}