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
        ll n, k;
        cin>>n>>k;

        if(n%4==0)
        {
            cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        }
        else if(n%2==0)
        {
            cout<<n/2-1<<" "<<n/2-1<<" "<<2<<endl;
        }
        else
        {
            cout<<n/2<<" "<<n/2<<" "<<1<<endl;
        }
    }

    return 0;
}

