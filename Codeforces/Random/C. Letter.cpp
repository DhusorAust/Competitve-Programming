#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans1[100009],ans2[100009];
int main()
{
   string s;
   cin>>s;
   ll n = s.length();
   ll cnt1 = 0,cnt2 = 0;

   for(ll i=0;i<n;i++)
   {
       if(s[i]>='A' && s[i]<='Z')
          cnt1++;
       else
          cnt2++;
   }

   if(s[0]>='A' && s[0]<='Z')
      ans1[0] = 1;
   else
      ans2[0] = 1;

   for(ll i=1;i<n;i++)
   {
       if(s[i]>='A' && s[i]<='Z')
         ans1[i] = ans1[i-1]+1;
       else
         ans1[i] = ans1[i-1];

       if(s[i]>='a' && s[i]<='z')
         ans2[i] = ans2[i-1]+1;
       else
         ans2[i] = ans2[i-1];
   }

   ll ans3 = min(cnt1,cnt2);

   for(ll i=0;i<n;i++)
   {
      ans3 = min(ans3,cnt1-ans1[i]+ans2[i]);
   }

   cout<<ans3<<endl;
   return 0;

}
