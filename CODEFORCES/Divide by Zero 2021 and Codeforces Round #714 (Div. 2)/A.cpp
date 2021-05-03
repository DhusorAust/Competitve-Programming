#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
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
        ll arr[n+9];
        ll x = n/2;
        if(n%2==0)
            x--;
        if(k>x)
        {
            cout<<-1<<endl;
            continue;
        }
        ll y = 1;
        for(ll i = 1;i<=n;i+=2)
        {
            arr[i] = y;
            y++;
        }
        for(ll i = 2;i<=n;i+=2)
        {
            arr[i] = y;
            y++;
        }
        ll tmp = k*2+2;

        sort(arr+tmp,arr+n+1);
        for(ll i = 1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    return 0;
}

