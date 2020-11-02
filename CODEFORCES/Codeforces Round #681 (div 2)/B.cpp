#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll a, b;
        cin>>a>>b;

        string s;
        cin>>s;

        ll n = s.size();

        vector<ll> v;

        ll I1=n,  I2=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                I1 = i;
                break;
            }
        }

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                I2 = i;
                break;
            }
        }

        ll one = 0;
        for(ll i = I1;i<=I2;i++)
        {
            if(i!=0 && s[i]=='1' && s[i-1]=='1')
                continue;
            v.push_back(s[i]-48);
            if(s[i]-48==1)
                one++;
        }

        if(v.size()==0)
        {
            cout<<"0"<<endl;
        }
        else if(v.size()==1)
        {
            cout<<a<<endl;
        }
        else
        {
            vector<ll> v2;
            ll cnt = 1;
            ll cnt2 = 0;
            for(ll i =1;i<v.size();i++ )
            {
                if(v[i]==1)
                    cnt++;
                else
                    cnt2++;
                if(cnt==2)
                {
                    v2.push_back(cnt2);
                    cnt = 1;
                    cnt2 = 0;
                }
            }

             ll sum = a*one;

             for(ll i =0;i<v2.size();i++ )
             {
                 if(v2[i]*b<a)
                 {
                     sum+= v2[i]*b-a;
                 }
             }

             cout<<sum<<endl;
        }
    }

    return 0;
}




