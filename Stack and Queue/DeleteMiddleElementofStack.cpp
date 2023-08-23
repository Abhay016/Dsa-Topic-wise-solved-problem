
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void solve(stack<int> &s, int n)
{
    if (n == 0)
    {
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    solve(s, n - 1);
    s.push(top);
}
void deleteMid(stack<int> &s, int sizeOfStack)
{
    solve(s, sizeOfStack / 2);
}

int main()
{
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    deleteMid(s, s.size());
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}