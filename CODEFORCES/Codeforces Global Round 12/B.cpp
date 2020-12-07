#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n, k;
struct node{
ll x, y;
};
ll dis(ll x1, ll y1, ll x2, ll y2)
{
    return (abs(x1-x2)+abs(y1-y2));
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {

        cin>>n>>k;

        node arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i].x>>arr[i].y;
        }

        bool bol = false;
        for(ll i = 0;i<n;i++)
        {
            bool bol2 = true;
            for(ll j = 0;j<n;j++)
            {
                if(dis(arr[i].x,arr[i].y,arr[j].x,arr[j].y)>k){
                     bol2 = false;
                     break;
                }
            }

            if(bol2)
            {
                bol = true;
                break;
            }
        }

        if(bol)
            cout<<1<<endl;
        else
            cout<<-1<<endl;


    }

    return 0;
}

