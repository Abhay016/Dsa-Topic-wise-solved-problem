#include <bits/stdc++.h>
using namespace std;

void Sort(stack<int> &stack, int x)
{
	if(stack.empty() || stack.top()<x)
	{
		stack.push(x);
		return;
	}
	int top=stack.top();
	stack.pop();
	Sort(stack, x);
	stack.push(top);
} 
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
	{
		return;
	}
	int top=stack.top();
	stack.pop();
	sortStack(stack);
	Sort(stack, top);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);
    stack<int> temp(s);
    cout<<endl<<"Before sorting: "<<endl;
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    sortStack(s);
    cout<<endl<<"After sorting: "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}