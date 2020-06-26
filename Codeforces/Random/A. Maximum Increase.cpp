#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int main()
{
    FAST;

    ll n;
    cin>>n;

    ll arr[n];
    ll ans[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ans[i] = 1;
    }

    ll maax = ans[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
            ans[i] = ans[i]+ans[i+1];
        maax = max(maax,ans[i]);
    }

    cout<<maax<<endl;


    return 0;
}
