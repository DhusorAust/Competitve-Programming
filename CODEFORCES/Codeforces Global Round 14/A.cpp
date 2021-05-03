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
        ll n,x;
        cin>>n>>x;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        vector<ll> v;
        sort(arr,arr+n);
        ll sum = 0;
        bool bol = true;
        for(ll i  =0;i<n;)
        {
            sum+=arr[i];
            if(sum==x)
            {
                if(i+1<=n-1)
                {
                    v.push_back(arr[i+1]);
                    v.push_back(arr[i]);
                    sum+=arr[i+1];
                    i+=2;
                }
                else
                {
                    bol = false;
                    break;
                }
            }
            else
            {
                v.push_back(arr[i]);
                i++;
            }
        }
        if(bol)
        {
            cout<<"YES"<<endl;
            for(ll i = 0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


    }

    return 0;
}

