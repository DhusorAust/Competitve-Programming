#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll n,l;
    cin>>n>>l;

    ll arr[n];

    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort(arr,arr+n);

    ll maax = -1;
    for(ll i = 1;i<n;i++)
    {
        maax = max(maax,arr[i]-arr[i-1]);
    }

    ll maax2 = arr[0]-0;
    maax2 = max(maax2,l-arr[n-1]);

    if(maax2*2>maax)
        cout<<maax2<<endl;
    else
    {
        cout<<maax/2;
        if(maax%2!=0)
            cout<<".5"<<endl;
    }



    return 0;
}

