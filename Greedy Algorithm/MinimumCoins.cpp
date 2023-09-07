
#include <bits/stdc++.h> 
using namespace std;

int minimumCoins(int p)
{
    int arr[]={1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int i=0;
    int count=0;
    while(p>0)
    {
        while(i<9 && p<arr[i])
        {
            i++;
        }
        count+=p/arr[i];
        p=p%arr[i];
    }
    return count;
}

int main()
{
    cout<<minimumCoins(24);
}