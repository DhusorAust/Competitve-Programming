#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;


int main()
{
    FAST
    ll t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        ll n = s.size();
        ll cnt = 0;
        for(ll i = 0;i<n;i++)
        {
            if(s[i]=='a')
                cnt++;
        }
        if(cnt==n)
            cout<<"NO";
        else
        {
            cout<<"YES"<<endl;
            ll I1,I2;
            for(ll i = 0;i<n;i++)
            {
                if(s[i]!='a')
                {
                    I1 = i;
                    break;
                }
            }
            for(ll i = n-1;i>=0;i--)
            {
                if(s[i]!='a')
                {
                    I2 = i;
                    break;
                }
            }
            if(n%2==0)
            {
                if(I1<n/2)
                {
                    for(ll i = 0;i<n;i++)
                    {

                        cout<<s[i];
                        if(n-I1-1==i)
                        {
                            cout<<'a';
                        }
                    }
                }
                else
                {
                    for(ll i = 0;i<n;i++)
                    {
                        if(n-I2-1==i)
                        {
                            cout<<'a';
                        }
                        cout<<s[i];
                    }
                }
            }
            else
            {
                if(I1<=n/2)
                {
                    for(ll i = 0;i<n;i++)
                    {

                        cout<<s[i];
                        if(n-I1-1==i)
                        {
                            cout<<'a';
                        }
                    }
                }
                else
                {
                    for(ll i = 0;i<n;i++)
                    {
                        if(n-I2-1==i)
                        {
                            cout<<'a';
                        }
                        cout<<s[i];
                    }
                }
            }

        }
        cout<<endl;
    }

    return 0;
}

