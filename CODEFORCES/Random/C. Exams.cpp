#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

struct node
{
    ll a,b;
};

bool cmp(node a, node b)
{
    if(a.a==b.a)
        return a.b<b.b;
    return a.a<b.a;
}
int main()
{
    FAST

    ll n;
    cin>>n;

    node arr[n];

    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i].a>>arr[i].b;
    }

    sort(arr,arr+n,cmp);

    ll maax = arr[n-1].b;
    ll ans = arr[n-1].a;

    ll tmp = -1;
    for(ll i = 0;i<n-1;i++)
    {
       if(arr[i].b>=tmp)
           tmp = arr[i].b;
       else
           tmp = arr[i].a;

       if(tmp>maax)
       {
           cout<<ans<<endl;
           return 0;
       }
    }

    cout<<maax<<endl;

    return 0;
}

