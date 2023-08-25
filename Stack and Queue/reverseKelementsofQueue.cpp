
#include <bits/stdc++.h>
using namespace std;

void rev(queue<int> &q, int k)
{
    if (k == 0)
    {
        return;
    }
    int front = q.front();
    q.pop();
    rev(q, k - 1);
    q.push(front);
}

void modifyQueue(queue<int>& q, int k)
{
    rev(q, k);
    int i = q.size() - k;
    while (i--)
    {
        int front = q.front();
        q.pop();
        q.push(front);
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    queue<int> temp(q);
    cout<<"Before reversing: "<<endl;
    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    modifyQueue(q, 4);
    cout<<endl<<"After reversing: "<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    } 
}