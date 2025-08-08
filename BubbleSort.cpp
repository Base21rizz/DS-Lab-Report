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
    int count = 1;
    while (count<n)
    {
        for (int i = 0; i < n-1; i++)
        {
            if(v[i] > v[i+1])
            {
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
        count++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    
    return 0;
}