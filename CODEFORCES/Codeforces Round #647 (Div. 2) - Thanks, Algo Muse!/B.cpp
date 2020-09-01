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

       ll m[1024],m2[1024];
       memset(m,0,sizeof(m));
       for(ll i = 0;i<n;i++)
       {
           cin>>arr[i];
           m[arr[i]]++;
       }

       /*  for(ll i=0;i<10;i++)
           {
               cout<<m[i]<<" ";
           }
           cout<<endl;*/

       bool bol = false;
       for(ll i = 1;i<1024;i++)
       {
           memset(m2,0,sizeof(m2));
           for(ll j = 0;j<n;j++)
           {
                //cout<<"eta "<<i<<" "<<arr[j]<<" "<<(arr[j]^i)<<endl;
               m2[arr[j]^i]++;
           }

          /* for(ll i=0;i<10;i++)
           {
               cout<<m2[i]<<" ";
           }
           cout<<endl;*/

           bool bol2 = true;
           for(ll j = 0;j<1024;j++)
           {
               if(m[j]!=m2[j])
               {
                   bol2 = false;
                   break;
               }
           }
           if(bol2)
           {
               cout<<i<<endl;
               bol = true;
               break;
           }
       }
       if(!bol)
        cout<<-1<<endl;
    }

    return 0;
}

