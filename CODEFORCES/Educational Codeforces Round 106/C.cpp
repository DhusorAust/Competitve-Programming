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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        priority_queue<int, vector<int>, greater<int> >q1, q2;
        ll ans2 = n*arr[0]+n*arr[1];
        q1.push(arr[0]);
        q2.push(arr[1]);
        ll x = 1;
        ll y = 1;
        ll sum = arr[0]+arr[1];
        for(ll i  = 2;i<n;i++)
        {
            sum+=arr[i];
            if(i%2==0)
            {
                x++;
                q1.push(arr[i]);
            }
            else
            {
                y++;
                q2.push(arr[i]);
            }
            ll ans = sum + q1.top()*(n-x)+q2.top()*(n-y);
            ans2 = min(ans,ans2);
        }
        cout<<ans2<<endl;
    }
    return 0;
}


