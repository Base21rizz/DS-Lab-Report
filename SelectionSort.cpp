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
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if(v[j] < v[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    
    return 0;
}