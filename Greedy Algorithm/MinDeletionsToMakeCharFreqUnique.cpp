
#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s)
{
    vector<int> vec(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        vec[s[i] - 'a']++;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int res = 0;
    int maxFreq = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > maxFreq)
        {
            if (maxFreq > 0)
                res += vec[i] - maxFreq;
            else
                res += vec[i];
        }
        maxFreq = min(maxFreq - 1, vec[i] - 1);
    }
    return res;
}

int main()
{
    cout<<minDeletions("accdcdadddbaadbc");
}