
#include <bits/stdc++.h> 
using namespace std;

void permutation(string s, vector<string>& res, int idx)
{
    if(idx==s.length())
    {
        res.push_back(s);
        return;
    }
    for(int i=idx; i<s.length(); i++)
    {
        swap(s[i], s[idx]);
        permutation(s, res, idx+1);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> res;
    permutation(s, res, 0);
    return res;
}

int main()
{
    string s="123";
    vector<string> res=findPermutations(s);
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
}