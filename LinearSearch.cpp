#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int target;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        if(v[i] == target)
        {
            cout << "Index: " << i << endl;
            cout << "Position: " << i+1 << endl;
        }
    }
    return 0;
}