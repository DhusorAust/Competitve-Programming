#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

ll F(ll arr[], ll n, ll k, ll L)
{
    ll sum = L;

    ll tmp = k;

    ll cnt2 = 1;

    while(tmp<arr[L])
    {
        tmp*=2;
        cnt2++;
    }

    sum+= cnt2;

    for(ll i = L+1;i<n;i++)
    {
        ll cnt2 = 1;

        ll tmp = arr[i-1]*2;

        while(tmp<arr[i])
        {
            tmp*=2;
            cnt2++;
        }

        sum+=cnt2;
    }

    return sum;
}

int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k;

        cin>>n>>k;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n);

        ll L = lower_bound(arr,arr+n,k)-arr;

        ll ans1 =  F(arr,n,k,L);

        ll ans2 = INT_MAX;

        if(L!=0)
        {
            ll L2 = L-1;

            ans2 =  F(arr,n,k,L2);
        }

        cout<<min(ans1,ans2)<<endl;
    }

    return 0;
}

