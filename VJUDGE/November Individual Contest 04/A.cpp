#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

map<char,ll> m;

char arr(ll i)
{
    return i+97;
}
string dp[30][1009];
string f(ll i, ll freq)
{

    if(dp[i][freq]!="-1")
        return dp[i][freq];
    if(i==26)
        return dp[i][freq] = "-";

    string a,b;
    if(m[arr(i)]>=freq && m[arr(i)]!=0)
    {
       a =  f(i+1,m[arr(i)]);
    }

    b = f(i+1,freq);

    string s;
    s.push_back(arr(i));
    s += a;

    if(s.size()==b.size())
    {
        return dp[i][freq] = min(s,b);
    }

    if(s.size()>b.size())
    {
        return dp[i][freq] = s;
    }

    return dp[i][freq] = b;
}

int main()
{
    FAST

   // cout<<arr(25)<<endl;

    ll t;
    cin>>t;

    while(t--)
    {
        m.clear();

        for(int i=0;i<30;i++)
        {
            for(int j = 0;j<1009;j++)
            {
                dp[i][j] = "-1";
            }
        }
        string s;
        cin>>s;

        for(ll i = 0;i<s.size();i++)
        {
            m[s[i]]++;
        }



        string ans = f(0,0);
        for(int i=0;i<ans.size()-1;i++)
        {
            cout<<ans[i];
        }

        cout<<endl;

    }

    return 0;
}

