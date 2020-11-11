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
        ll n, m;
        cin>>n>>m;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        vector<ll> v;
        bool bol = false;
        ll i, j, k =0;
        for( i = 0, j = n-1,k=0;k<min(m,n);k++)
        {
            if(k%2==0)
            {
                v.push_back(arr[i]);
                i++;
                bol =true;
            }
            else
            {
                v.push_back(arr[j]);
                j--;
                bol = false;
            }
        }

       // cout<<i<<" "<<j<<" "<<bol<<endl;
        if(bol)
        {
            for(;i<=j;i++)
            {
                v.push_back(arr[i]);
            }
        }
        else
        {
            for(;i<=j;j--)
            {
                v.push_back(arr[j]);
            }
        }

        for(ll i = 0;i<v.size()-1;i++)
        {
            cout<<v[i]<<" ";
        }

        cout<<v[v.size()-1]<<endl;
    }

    return 0;
}

