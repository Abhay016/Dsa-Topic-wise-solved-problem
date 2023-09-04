
/*
    Given two strings S and P. Find the smallest window in the string
S consisting of all the characters(including duplicates) of the string P.
  Return "-1" in case there is no such window present. In case there are
multiple such windows of same length, return the one with the least starting index.
*/

#include <bits/stdc++.h>
using namespace std;

string smallestWindow(string s, string p)
{
    // Your code here
    unordered_map<char, int> mp;
    int count = 0;
    for (int i = 0; i < p.length(); i++)
    {
        if(mp[p[i]]==0)
        count++;
        mp[p[i]]++;
    }
    int start = 0, i = 0;
    int end = INT_MAX, j = 0;
    while (j < s.length())
    {
        mp[s[j]]--;
        if(mp[s[j]]==0)
        count--;
        if (count==0)
        {
            while(count==0)
            {
                if(j-i<end-start)
                {
                    start=i;
                    end=j;
                }
            mp[s[i]]++;
            if(mp[s[i]]==1)
            count++;
            i++;
            }
        }
        j++;
    }
    string res = "";
    for (int i = start; i <= end; i++)
    {
        res.push_back(s[i]);
    }
    return res;
}

int main()
{
    cout<<smallestWindow("zoomlazapzo", "oza");
}