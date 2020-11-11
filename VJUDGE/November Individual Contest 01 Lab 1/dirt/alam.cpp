#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ll n, k;
   cin>>n>>k;
   map<char, ll> m;
   string s;
   cin>>s;
   set<char> st;
   for(ll i = 0;i<n;i++)
   {
       m[s[i]]++;
       st.insert(s[i]);
   }

   for(auto it  = st.begin();it!=st.end();it++)
   {
       if(m[*it]%2!=0 && k>=1)
       {
           m[*it]++;
           k--;
       }
   }
   if(k!=0)
   {
       ll ans = 0;
       for(auto it  =st.begin();it!=st.end();it++)
       {
           ans+=m[*it];
       }
       cout<<ans+k<<endl;
   }
   else if(k==0)
   {
       ll ans = 0;
       bool bol = false;
       for(auto it  =st.begin();it!=st.end();it++)
       {
           if(m[*it]%2==0)
                ans+=m[*it];
           else
           {
               ans+=m[*it]-1;
               bol = true;
           }
       }
       if(bol)
            ans = ans+1;
       cout<<ans<<endl;
   }




    return 0;
}
