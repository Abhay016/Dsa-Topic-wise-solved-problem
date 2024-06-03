
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
    int n;
    cin>>n;
    int res=0;
    int i=0;
    while(n!=0)
    {
        if(n%2)
        {
            res=pow(2, i)+res;
        }
        i++;
        n=n/10;
    }
    cout<<res;
    return 0;
}