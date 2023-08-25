
#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if (q.size() == 1)
    {
        return;
    }
    int front = q.front();
    q.pop();
    reverse(q);
    q.push(front);
}
void rev(queue<int> &q)
{
    reverse(q);
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    queue<int> temp(q);
    cout<<"Before reversing: "<<endl;
    while(!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }
    rev(q);
    cout<<endl<<"After reversing: "<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    } 

}