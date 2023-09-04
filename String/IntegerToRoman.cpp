
#include <bits/stdc++.h>
using namespace std;

string solve(int j)
{
    switch (j)
    {
    case 0:
        return "I";
    case 1:
        return "IV";
    case 2:
        return "V";
    case 3:
        return "IX";
    case 4:
        return "X";
    case 5:
        return "XL";
    case 6:
        return "L";
    case 7:
        return "XC";
    case 8:
        return "C";
    case 9:
        return "CD";
    case 10:
        return "D";
    case 11:
        return "CM";
    case 12:
        return "M";
    }
    return " ";
}
string intToRoman(int num)
{
    string res;
    int arr[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    for (int i = 12; i >= 0 && num > 0; i--)
    {
        if (num >= arr[i])
        {
            int div = num / arr[i];
            while (div--)
            {
                res.append(solve(i));
            }
            num = num % arr[i];
        }
    }
    return res;
}

int main()
{
    cout<<intToRoman(1994);
}