/*   You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.   */

#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, string str)
{
    if (str == "+")
        return a + b;
    else if (str == "-")
        return b - a;
    else if (str == "*")
        return a * b;
    else
        return b / a;
}
int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(solve(a, b, tokens[i]));
        }
        else
        {
            int temp = stoi(tokens[i]);
            s.push(temp);
        }
    }
    return s.top();
}

int main()
{
    vector<string> tokens={"2","1","+","3","*"};
    cout<<evalRPN(tokens);
}