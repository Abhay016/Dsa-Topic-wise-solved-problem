
/* Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s. */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool rotateString(string s, string goal)
{

    if (s.size() != goal.size())
    {
        return false;
    }
    s.append(s);
    if (s.find(goal) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout<<rotateString("abcde", "cdeab");
}