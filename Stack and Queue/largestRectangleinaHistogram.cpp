
#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> arr)
{
    stack<int> s;
    vector<int> prev(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            prev[i] = -1;
        else
            prev[i] = s.top();
        s.push(i);
    }
    return prev;
}

vector<int> nextSmaller(vector<int> arr)
{
    stack<int> s;
    vector<int> next(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            next[i] = arr.size();
        else
            next[i] = s.top();
        s.push(i);
    }
    return next;
}

int largestRectangleArea(vector<int> &heights)
{
    int res = 0;
    vector<int> prev = prevSmaller(heights);
    vector<int> next = nextSmaller(heights);
    for (int i = 0; i < heights.size(); i++)
    {
        int area = (next[i] - prev[i] - 1) * heights[i];
        res = max(res, area);
    }
    return res;
}

int main()
{
    vector<int> arr={2,1,5,6,2,3};
    cout<<largestRectangleArea(arr);
}