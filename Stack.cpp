#include <bits/stdc++.h>
using namespace std;
const int N = 1e+5;
int stack_[N];
int n;
int top = -1;
void push()
{
    int x;
    cout << "Your data to insert: ";
    cin >> x;
    if (top == n - 1)
    {
        cout << "!Overflow!" << endl;
    }
    else
    {
        top++;
        stack_[top] = x;
    }
}
void pop()
{
    int y;
    if (top == -1)
    {
        cout << "!Underflow!";
    }
    else
    {
        y = stack_[top];
        top--;
        cout << "Deleted Value: " << y << endl;
    }
}
void display()
{
    for (int i = top; i >= 0; i--) cout << stack_[i] << ' ' << endl;
    cout << endl;
}
int main()
{
    cout << "Size of stack_: ";
    cin >> n;
    cout << "How many functions do you want to do: " << endl;
    int functions;
    cin >> functions;
    cout << "type the following for the function you want to use: push for Push(),pop for Pop(),display for Display(),top/peek for Top()/peek(),isfull/isempty" << endl;
    
    while (functions--)
    {
        cout << "Your function: ";
        string s;
        cin >> s;
        if (s == "push") push();
        else if (s == "pop") pop();
        else if (s == "display") display();
        else if (s == "top" || s== "peek")
        {
            cout << stack_[top] << endl;
        }
        else if(s == "isfull")
        {
            if(top == n-1) cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }
        else if(s == "isempty")
        {
            if(top == -1) cout << "Yes!" << endl;
            else cout << "No!" << endl;
        }
    }
}