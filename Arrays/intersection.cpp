
/*   Intersection of two arrays   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void intersection(int *input1, int *input2, int size1, int size2)
{
    unordered_map<int, int> mp;
    for(int i=0; i<size2; i++)
    {
        mp[input2[i]]++;
    }
    vector<int> vec;
    for(int i=0; i<size1; i++)
    {
        if(mp.count(input1[i]))
        {
            vec.push_back(input1[i]);
            mp[input1[i]]--;
            if(mp[input1[i]]==0)
            mp.erase(input1[i]);
        }
    }
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
}

int main()
{
    int input1[]={2, 6, 8, 5, 4, 3};
    int input2[]={2, 3, 4, 7};
    intersection(input1, input2, 6, 4);
}