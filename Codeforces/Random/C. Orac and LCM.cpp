#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ll n;
   cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   ll gcd[n];
   gcd[n-1] =arr[n-1];
   for(int i=n-2;i>=1;i--)
   {
       gcd[i] = __gcd(gcd[i+1],arr[i]);
   }
   for(int i=1;i<n;i++)
   {
      gcd[i] = arr[i-1]*gcd[i]/__gcd(gcd[i],arr[i-1]);
   }
   ll ans = gcd[1];
   for(int i=2;i<n;i++)
   {
      ans = __gcd(ans,gcd[i]);
   }
   cout<<ans<<endl;
   return 0;
}
