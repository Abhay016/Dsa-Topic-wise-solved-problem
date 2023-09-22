
/*

*
* *
* * * 
* * * *
* * * * *

*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    if(n==0)
    return;
    solve(n-1);
    for(int i=0; i<n; i++)
    {
        cout<<"* ";
    }
    cout<<endl;
}
int main()
{
    solve(5);
}