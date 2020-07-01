#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

   ll n,m;
   cin>>n>>m;

   set<ll> s;
   for(ll i = 0;i<m;i++)
   {
       ll u,v;
       cin>>u>>v;
       s.insert(u);
       s.insert(v);
   }

   ll used = s.size();

   ll M = n-used;

   ll sum = 1;

   ll N = n-1;

   for(ll i=1;i<=M;i++)
   {
       sum*=N;
   }

   ll bad = (M*(M-1))/2;

   cout<<sum-bad<<endl;

    return 0;
}
