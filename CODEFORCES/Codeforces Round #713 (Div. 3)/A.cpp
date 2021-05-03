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
        ll n;
        cin>>n;

        ll arr[n], arr2[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            arr2[i] = arr[i];
        }

        sort(arr,arr+n);

        ll ans;
        if(arr[0]==arr[1])
        {
            for(ll i = 0;i<n;i++)
            {
                if(arr2[i]==arr[n-1])
                {
                    ans = i+1;
                    break;
                }
            }

        }
        else
        {
            for(ll i = 0;i<n;i++)
            {
                if(arr2[i]==arr[0])
                {
                    ans = i+1;
                    break;
                }
            }
        }

        cout<<ans<<endl;


    }

    return 0;
}


