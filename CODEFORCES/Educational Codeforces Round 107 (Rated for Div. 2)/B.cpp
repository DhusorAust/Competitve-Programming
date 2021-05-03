
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;

string maax (string s1, string s2)
{
    if(s1.size()>s2.size())
        return s1;
    if(s1.size()<s2.size())
        return s2;

    for(ll i = 0;i<s1.size();i++)
    {
        if(s1[i]>s2[i])
            return s1;
        if(s1[i]<s2[i])
            return s2;
    }
    return s1;
}

string miin (string s1, string s2)
{
    if(s1.size()<s2.size())
        return s1;
    if(s1.size()>s2.size())
        return s2;

    for(ll i = 0;i<s1.size();i++)
    {
        if(s1[i]<s2[i])
            return s1;
        if(s1[i]>s2[i])
            return s2;
    }
    return s1;
}
int main()
{
    FAST

    //cout<<__gcd(100000,110)<<endl;



    ll t;
    cin>>t;
    while(t--)
    {
       ll a, b, c;
       cin>>a>>b>>c;
       ll mx = max(a,b);
       ll mn = min(a,b);

       string s1, s2;

       s1.push_back('1');
       s2.push_back('1');
       for(ll i = 0;i<mx-1;i++)
         s1.push_back('0');

       for(ll i = 0;i<mn-1;i++)
         s2.push_back('0');

       for(ll i = 1,j= 0;j<mn-c;i++,j++)
        s2[i] = '1';


       if(a<b)
          cout<<miin(s1,s2)<<" "<<maax(s1,s2)<<endl;
       else
         cout<<maax(s1,s2)<<" "<<miin(s1,s2)<<endl;

    }

    return 0;
}

