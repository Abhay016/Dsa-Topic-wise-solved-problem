
/*

    A 
    B C
    C D E
    D E F G

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=4;
    for(int i=1; i<=n; i++)
    {
        char ch='A'+i-1;
        for(int j=1; j<=i; j++)
        {
            cout<<ch++<<" ";
        }
        cout<<endl;
    }
}