#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
       ll n,k;
       cin>>n>>k;

       ll arr[n];
       ll ans[n];

       ll sum = 0;
       for(ll i=0;i<n;i++)
       {
           cin>>arr[i];
           ans[i] = arr[i]%k;
           ans[i] = k-ans[i];
           if(ans[i]==k)
            ans[i] = 0;
           sum+=ans[i];
       }

       map<ll,ll> m;
       ll maax = 1;
       ll ans2 = -1;
       for(ll i=0;i<n;i++)
       {
           if(ans[i]==0)
            continue;
           m[ans[i]]++;
           if(m[ans[i]]>maax)
           {
               maax = m[ans[i]];
               ans2 = ans[i];

           }
           else if(m[ans[i]]==maax)
           {
               if(ans[i]>ans2)
               {
                   maax = m[ans[i]];
                   ans2 = ans[i];
               }
           }
       }

       cout<<(maax-1)*k+ans2+1<<endl;  
    }
    return 0;
}

