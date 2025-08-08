#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i=n+1;i>0;i--)
    {
        arr[i] = arr[i-1];
    }
    int input;
    cin >> input;
    arr[0] = input;
    for (int i = 0; i < n+1; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
