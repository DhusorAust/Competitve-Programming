#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll X[n], Y[n];
        for(ll i =0 ;i<n;i++)
        {
            cin>>X[i]>>Y[i];
        }
        if(n%2==1)
        {
            cout<<1<<endl;
            continue;
        }
        sort(X,X+n);
        sort(Y,Y+n);
        ll x1 = n/2;
        ll x2 = x1-1;
        ll y1 = n/2;
        ll y2 = y1-1;
        cout<<(X[x1]-X[x2]+1)*(Y[y1]-Y[y2]+1)<<endl;
    }
    return 0;
}

