
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;


ll point(string s)
{
    ll n = s.length();
    ll sum = 0;
    for(ll i = 0;i<n;i++)
    {
        sum+=(s[i]-48);
    }
    return sum;
}


int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
       ll n;
       cin>>n;
       vector< pair<string,string> > v;

       for(ll i=0;i<n;i++)
       {
           string s1, s2;
           cin>>s1>>s2;

           v.push_back(make_pair(s1,s2));
       }

       ll cnt1 = 0,cnt2 = 0;
       for(ll i=0;i<n;i++)
       {
           string s1 = v[i].first;
           string s2 = v[i].second;

           ll p1 = point(s1);
           ll p2 = point(s2);

           if(p1>p2)
           {
               cnt1++;
           }
           else if (p1==p2)
           {
               cnt1++;
               cnt2++;
           }
           else
           {
               cnt2++;
           }
       }

       if(cnt1>cnt2)
       {
           cout<<"0 ";
       }
       else if (cnt2>cnt1)
       {
           cout<<"1 ";
       }
       else
       {
           cout<<"2 ";
       }

       cout<<max(cnt1,cnt2)<<endl;
    }

    return 0;
}

