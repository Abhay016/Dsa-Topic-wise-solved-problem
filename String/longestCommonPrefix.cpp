
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string pre = "";
    int k = 0;
    for (int i = 0; i < strs[0].size(); i++)
    {
        int flag = 0;
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[0][k] != strs[j][k])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            pre.push_back(strs[0][k]);
            k++;
        }
        else
            return pre;
    }
    return pre;
}

int main()
{
    vector<string> strs={"flower", "flying", "flow"};
    cout<<longestCommonPrefix(strs);
}
