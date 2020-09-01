#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
#define pb push_back

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

       sort(arr,arr+n);

       ll ans = 0;
       for(ll i = 2;i<=2*n;i++)
       {
           ll cnt = 0;
           for(ll j = 0,k = n-1;j<k;)
           {
               if(arr[j]+arr[k]==i)
               {
                   j++;
                   k--;
                   cnt++;
               }
               else if(arr[j]+arr[k]>i)
               {
                   k--;
               }
                else if(arr[j]+arr[k]<i)
               {
                   j++;
               }
           }
           ans = max(ans,cnt);
       }

       cout<<ans<<endl;

    }






    return 0;
}

