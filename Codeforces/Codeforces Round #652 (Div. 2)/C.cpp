#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ll t;
   cin>>t;

   while(t--)
   {
       ll n,k;
       cin>>n>>k;

       ll arr[n],arr2[k],ans[k];

       for(ll i=0;i<n;i++)
       {
           cin>>arr[i];
       }

       for(ll i=0;i<k;i++)
       {
           cin>>arr2[i];
       }
       sort(arr,arr+n);
       sort(arr2,arr2+k);
       ll sum  = 0;
       ll lst = n-1;
       for(int i=0;i<k;i++)
       {
           if(arr2[i]==1)
           {
               ans[i] = arr[lst]+arr[lst];
               lst--;
               arr2[i] = 0;
           }
           else if(arr2[i]==2)
           {
               ans[i] = arr[lst];
               lst--;
               ans[i] += arr[lst];
               lst--;
               arr2[i] = 0;
           }
           else
           {
               ans[i] = arr[lst];
               lst--;
               arr2[i]--;
           }

           sum+=ans[i];
       }
       ll fst = 0;
       for(ll i =k-1;i>=0;i--)
       {
           for(ll j = 0;j<arr2[i];j++,fst++)
           {
               if(j==0)
               {
                   ans[i] += arr[fst];
                   sum += arr[fst];
               }
           }
       }

       cout<<sum<<endl;
   }

   return 0;
}
