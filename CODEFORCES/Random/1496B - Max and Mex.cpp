
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        ll arr[n];
        for(ll i  = 0;i<n;i++)
            cin>>arr[i];
        if(k==0)
        {
            cout<<n<<endl;
            continue;
        }
        sort(arr,arr+n);
        ll maax = arr[n-1];
        ll mex = 0;
        for(ll i = 0;i<n;i++)
        {
            if(arr[i]==mex)
                mex++;
            else
                break;
        }
        if(mex>maax)
            cout<<n+k<<endl;
        else
        {
            ll x = (mex+maax)/2;
            if((mex+maax)%2!=0)
                x++;
            ll i;
            for(i = 0;i<n;i++)
            {
                if(x==arr[i])
                    break;
            }
            if(i==n)
                cout<<n+1<<endl;
            else
                cout<<n<<endl;
        }
    }
    return 0;
}
