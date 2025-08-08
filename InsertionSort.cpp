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
        int current = v[i];
        int j = i-1;
        while (v[j] > current && j >= 0)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current;
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}