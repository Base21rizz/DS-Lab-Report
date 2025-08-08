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
    sort(v.begin(),v.end());
    int target;
    cin >> target;
    int mid=0,low=0,high=n;
    while(v[mid] != target)
    {
        mid = floor((low+high)/2);
        if(v[mid]<target)
        {
            low = mid+1;
        }
        else if(v[mid]>target)
        {
            high = mid-1;
        }
    }
    cout << "Index: " << mid << endl;
    cout << "Position: " << mid+1 << endl;
    return 0;
}