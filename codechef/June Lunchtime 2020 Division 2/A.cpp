#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

ll ans[32];

int main()
{
    FAST;

    int t;
    cin>>t;

   while(t--)
   {
       ll n,k;
       cin>>n>>k;

       for(int i=0;i<32;i++)
        ans[i] = 0;
       ll arr[n];
       ll len = 10000000000,len2 = -100000000000;
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           ll temp = arr[i];

           ll cnt = 0;
           while(temp!=0)
           {
              // cout<<temp%2<<endl;
              //
               if(temp%2 ==1)
                  ans[cnt] = 1;
                temp/=2;
                cnt++;
           }
           len = min(len,cnt);
           len2 = max(len2,cnt);
           //cout<<endl;
       }

       for(int i=len2-1;i>=0;i--)
       {
           cout<<ans[i];
       }
       cout<<endl;


   }



    return 0;
}


