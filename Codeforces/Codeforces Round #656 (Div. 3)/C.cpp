
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
       ll n;
       cin>>n;

       ll arr[n];

       for(ll i=0;i<n;i++)
       {
           cin>>arr[i];
       }

       ll tmp = arr[n-1];
       ll I = -1;
       ll cnt = 0;
       for(ll i=n-2;i>=0;i--)
       {
           if(arr[i]>=tmp)
           {
               tmp = arr[i];
               cnt++;
           }
           else
           {
               I = i;
               cnt++;
               break;
           }
       }
       tmp = arr[I];
       for(ll i = I-1;i>=0;i--)
       {
           if(arr[i]<=tmp)
           {
               tmp = arr[i];
               cnt++;
           }
           else
            break;
       }

       cout<<n-cnt-1<<endl;






    }

    return 0;
}

