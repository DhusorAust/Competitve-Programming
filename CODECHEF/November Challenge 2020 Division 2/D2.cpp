#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007

int main()
{
    FAST
    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll arr[n+9],ans[n+9];
        ans[0] = 0;
        bool exist = false;
        ll pos;
        for(ll i = 1;i<=n;i++)
        {
            cin>>arr[i];
            ans[i] = 0;
            if(arr[i]==1)
            {
                exist = true;
                pos = i;
            }
        }
        arr[0] = arr[n];

        for(ll i = 1;i<=n;i++)
        {
            if(arr[i]%2==0)
                ans[i] = (ans[i-1]%mod+arr[i]%mod)%mod;
            else
                ans[i] = (ans[i-1]%mod+arr[i]%mod-1%mod)%mod;
        }

        if(arr[n]%2==0)
        {
            ans[n]--;
        }
        else
        {
            ans[n]++;
            ans[n] = ans[n]%mod;
        }
        ll q;
        cin>>q;
        while(q--)
        {
            ll r;
            cin>>r;
            ll div,rem;
            div = r/n;
            rem = r%n;
            rem  = rem%mod;
            div = div%mod;
            ll out;
            if(!exist)
            {
                  out = (((div)%mod*ans[n]%mod)%mod + ans[rem]%mod)%mod;
                  if(rem!=0)
                  {
                      if(arr[rem]%2!=0)
                        out++;
                        out = out%mod;
                      cout<<out<<endl;
                  }
                  else
                  {
                      if(arr[rem]%2==0)
                        out++;
                        out = out%mod;
                      cout<<out<<endl;
                  }
            }
            else
            {
                if(pos==1)
                {
                   if(div==0)
                       out = 1;
                   else if(rem==0)
                       out = div;
                   else if(rem==1)
                       out = div;
                   else
                       out = div+1;
                       out = out%mod;
                   cout<<out<<endl;
                }
                else if(pos==n)
                {
                    out = ((ans[n]%mod*div%mod)%mod+ans[rem]%mod)%mod;
                    if(arr[rem]%2!=0 && rem!=0)
                        out++;
                        out = out%mod;
                    cout<<out<<endl;
                }
                else
                {
                    ll tot = ans[n];
                    if(arr[pos-1]%2!=0)
                        tot++;
                    else
                        tot--;
                    tot = tot%mod;
                    if(rem==pos)
                    {
                        out = ((tot%mod*div%mod)%mod + ans[rem]%mod+1)%mod;
                    }
                    else if(rem==pos-1)
                    {
                        out = ((tot%mod*div%mod)%mod + ans[rem]%mod)%mod;
                        if(arr[rem]%2!=0)
                           out = out+1;
                           out = out%mod;
                    }
                    else if(rem==0)
                    {
                        out = (tot%mod*div%mod)%mod;
                        if(arr[rem]%2==0)
                         out = out+1;
                         out = out%mod;
                    }
                    else
                    {
                        out =(( tot%mod*div%mod)%mod + ans[rem]%mod)%mod;
                        if(arr[rem]%2!=0)
                            out = out+1;
                        out = out%mod;
                        if(rem>pos)
                        {
                            if(arr[pos-1]%2!=0)
                                out++;
                            else
                                out--;
                        }
                        out = out%mod;

                    }
                    cout<<out<<endl;
                }
            }
        }
    }

    return 0;
}

