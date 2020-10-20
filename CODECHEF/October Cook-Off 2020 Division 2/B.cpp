
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

    int t;
    cin>>t;

    while(t--)
    {
        ll l,r;
        cin>>l>>r;

        ll L = l-1;

        if(l+L>=r)
        {
            ll diff = r-l;
            cout<<l+diff<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }


    }


    return 0;
}

