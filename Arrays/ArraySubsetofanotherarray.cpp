
/*   Array Subset of another array   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        mp[a1[i]]++;
    }
    for(int i=0; i<m; i++)
    {
        if(!mp.count(a2[i]))
        {
            return "No";
        }
        else
        {
            mp[a2[i]]--;
            if(mp[a2[i]]==0)
            {
                mp.erase(a2[i]);
            }
        }
    }
    return "Yes";
}

int main()
{
    int a1[]={11, 7, 1, 13, 21, 3, 7, 3};
    int a2[]={11, 3, 7, 1, 7};
    string str=isSubset(a1, a2, 8, 5);
    cout<<str;
}