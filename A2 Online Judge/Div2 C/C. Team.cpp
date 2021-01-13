#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll ans[2000009];

int main()
{
    FAST

    ll n, m;
    cin>>n>>m;

    if(n-m>1)
    {
        cout<<-1<<endl;
        return 0;
    }

    if(n>=m)
    {
        for(ll i = 0;i<m+n;i++)
        {
            if(i%2==0)
                cout<<0;
            else
                cout<<1;
        }
        cout<<endl;
        return 0;
    }

    if(m> 2*(n+1))
    {
        cout<<-1<<endl;
        return 0;
    }

    for(ll i = 0;i<2*n+1;i++)
    {
        if(i%2==0)
            ans[i] = 1;
        else
            ans[i] = 0;
    }

    ll rem = m - (n+1);

    for(ll i = 0 ;i<2*n+1;i++)
    {
        cout<<ans[i];
        if(ans[i]==1 && rem!=0)
        {
            cout<<1;
            rem--;
        }
    }

    cout<<endl;

    return 0;
}

