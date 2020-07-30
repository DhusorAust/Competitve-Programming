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
        ll n,k,z;
        cin>>n>>k>>z;

        ll arr[n];
        ll prex[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            prex[i] = arr[i];
        }

        for(ll i = 1;i<n;i++)
        {
            prex[i]+=prex[i-1];
        }

        ll sum  = 0;

        for(ll i = 0;i<=k;i++)
        {
           sum+=arr[i];
        }
  
        for(ll i = 1;i<=k;i++)
        {
               ll parbo = min((k-i)/2,z);    
               ll j = parbo*2;              
               ll sum2 = prex[k-j];                      
               sum2+=parbo*arr[i]+parbo*arr[i-1];
               if(z>parbo && (k-i)%2!=0)
               {
                   sum2+=arr[i-1]-arr[k-j];
               }  
               sum = max(sum,sum2);
        }
        cout<<sum<<endl;
    }
    return 0;
}


