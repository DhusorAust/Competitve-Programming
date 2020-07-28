#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

ll prex[500009];
ll n;

ll sum(ll i)
{
    return (prex[n]-prex[i-1]);
}
int main()
{
    FAST
    cin>>n;
    ll arr[n+1];

    prex[0] = 0;
    arr[0] = 0;

    for(ll i = 1;i<=n;i++)
    {
        cin>>arr[i];
        prex[i] = prex[i-1]+arr[i];
    }

    if(prex[n]%3!=0)
    {
        cout<<"0"<<endl;
        return 0;
    }

    ll div = prex[n]/3;

    ll cnt1[n+1],cnt2[n+1];

    cnt1[0] = 0;
    for(ll i = 1;i<=n;i++)
    {
        if(prex[i]==div)
            cnt1[i] = 1;
        else
            cnt1[i] = 0;
    }


    for(ll i = 1;i<=n;i++)
    {
        if(sum(i)==div)
            cnt2[i] = 1;
        else
            cnt2[i] = 0;
    }

    for(ll i = 1;i<=n;i++)
    {
        cnt1[i]+=cnt1[i-1];
    }

    ll ans = 0;
    for(ll i = 2;i<=n;i++)
    {
        if(cnt2[i]==1)
            ans+=cnt1[i-2];
    }

    cout<<ans<<endl;

    return 0;
}
