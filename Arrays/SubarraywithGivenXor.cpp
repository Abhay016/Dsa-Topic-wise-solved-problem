
#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector < int > a, int b) {
    unordered_map<int, int> mp;
    int x=0;
    mp[0]=1;
    int count=0;
    for(int i=0; i<a.size(); i++)
    {
        x=x^a[i];
        if(mp.count(x^b))
        {
            count+=mp[x^b];
        }
        mp[x]++;
    }
    return count;
}