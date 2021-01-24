#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define f first
#define s second
ll arr[2005];
ll m[2005];
int binarySearch(ll l, ll r, ll x)
{
    ll ans = -1;
    while (l <= r)
    {
        ll M = l + (r - l) / 2;

        if (arr[M] == x )
        {
            if(m[M]==0)
            {
                ans = M;
                r = M-1;
            }
            else
            {
                l =  M + 1;
            }
        }
        else if (arr[M] < x)
            l = M + 1;
        else
            r = M - 1;
    }

    return ans;
}
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll N = 2*n;


        for(ll i = 0;i<N;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+N);
        vector<ll> v;
        for(ll i = 0;i<N-1;i++)
        {
            v.pb(arr[N-1]+arr[i]);
        }
        ll X;
        vector< pair<ll,ll> > v2;
        bool bol2 = false;
        for(ll i = 0;i<v.size();i++)
        {
            ll x = v[i];
            X = x;
            memset(m,0,sizeof m);
            ll cnt = 0;
            v2.clear();
            for(ll j = N-1;j>=0;j--)
            {
                bool bol = true;

                if(m[j]==0)
                {
                    m[j] = 1;
                    ll second = x-arr[j];
                    ll L = binarySearch(0,j-1,second);
                    if(second>0 && arr[L] == second)
                    {
                        m[L] = 1;
                        x = arr[j];
                        cnt+=2;
                        bol = false;
                        v2.push_back(make_pair(arr[L],arr[j]));
                    }
                    if(bol)
                        break;
                }
           }
            if(cnt==N)
            {
                bol2 = true;
                break;
            }
      }
        if(bol2)
        {
            cout<<"YES"<<endl;
            cout<<X<<endl;
            for(ll i = 0;i<v2.size();i++)
            {
                cout<<v2[i].f<<" "<<v2[i].s<<endl;
            }
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

