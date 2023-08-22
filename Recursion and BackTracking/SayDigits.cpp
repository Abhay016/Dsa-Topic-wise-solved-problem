 
/*   Say Digits   */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string func(int digit)
{
    switch(digit)
    {
        case 1:
        return "One ";
        case 2:
        return "Two ";
        case 3:
        return "Three ";
        case 4:
        return "Four ";
        case 5:
        return "Five ";
        case 6:
        return "Six ";
        case 7:
        return "Seven ";
        case 8:
        return "Eight ";
        case 9:
        return "Nine ";
        case 0:
        return "Zero ";
    }
}
void sayDigits(int num, string &str)
{
    if(num==0)
    {
        return;
    }
    int rem=num%10;
    sayDigits(num/10, str);    
    str.append(func(rem));
}

int main()
{
    string str="";
    sayDigits(34543, str);
    cout<<str;
}