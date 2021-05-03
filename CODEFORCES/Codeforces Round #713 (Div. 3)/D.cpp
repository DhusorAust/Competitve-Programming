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

ll arr[200009], arr2[200009];
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i = 0;i<n+2;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n+2);

        ll sum = 0;
        for(ll i = 0;i<n+1;i++)
        {
            sum+=arr[i];
        }

        ll I = -1;
        for(ll i = 0;i<n+1;i++)
        {
            if(sum-arr[i]==arr[n+1])
            {
                I = i;
                break;
            }
        }
        vector<ll> v;
        if(I!=-1)
        {
            for(ll i = 0;i<n+2;i++)
            {
                if(i!=I)
                v.push_back(arr[i]);
            }
            v.push_back(arr[I]);
            for(ll i = 0;i<v.size()-2;i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
            continue;
        }

        ///

        sum = 0;
        for(ll i = 0;i<n+2;i++)
        {
            if(i!=n)
                sum+=arr[i];
        }

        I = -1;
        for(ll i = 0;i<n+2;i++)
        {
            if(i==n)
                continue;
            if(sum-arr[i]==arr[n])
            {
                I = i;
                break;
            }
        }
        if(I!=-1)
        {
            for(ll i = 0;i<n+2;i++)
            {
                if(i!=I)
                v.push_back(arr[i]);
            }
            v.push_back(arr[I]);
            for(ll i = 0;i<v.size()-2;i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        cout<<-1<<endl;

    }

    return 0;
}

