#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> s;
    for (int i = n - 1; i >= 0; i--)
    {
        long long temp = arr[i];
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            arr[i] = -1;
        else
            arr[i] = s.top();
        s.push(temp);
    }
    return arr;
}

int main()
{
    vector<long long> arr=nextLargerElement({1,3,2,4}, 4);
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" "; 
    }
}