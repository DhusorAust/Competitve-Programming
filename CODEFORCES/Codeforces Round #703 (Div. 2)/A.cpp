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
        ll n;
        cin>>n;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        if(n==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool bol = false;
        for(ll i = 0;i<n-1;i++)
        {
            if(arr[i]>=i)
            {
                arr[i+1] += (arr[i]-i);
            }
            else
            {
                bol = true;
            }
        }
        if(arr[n-1]<n-1)
            bol = true;
        if(bol)
            cout<<"NO"<<endl;
        else
           cout<<"YES"<<endl;

    }

    return 0;
}

