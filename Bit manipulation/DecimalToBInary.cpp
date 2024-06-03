
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
        int rem=n&1;
        res=(rem*pow(10, i))+res;
        n=(n>>1);
        i++;
    }
    cout<<res;
    return 0;
}