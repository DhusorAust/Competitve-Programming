#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

void print(ll x)
{
    cout<<"YES"<<endl;
    cout<<x<<endl;
}

int main()
{
    FAST
    string s;
    cin>>s;
    ll n = s.length();

    for(ll i = 0;i<n;i++)
    {
        ll x = s[i]-48;
        if(x%8==0)
        {
            print(x);
            return 0;
        }
    }

    for(ll i = 0;i<n-1;i++)
    {
        for(ll j = i+1;j<n;j++)
        {
                ll x = 10*(s[i]-48)+s[j]-48;
                if(x%8==0)
                {
                    print(x);
                    return 0;
                }
        }
    }

    for(ll i = 0;i<n-2;i++)
    {
        for(ll j = i+1;j<n-1;j++)
        {
            for(ll k = j+1;k<n;k++)
            {
                ll x = 100*(s[i]-48)+10*(s[j]-48)+s[k]-48;
                if(x%8==0)
                {
                    print(x);
                    return 0;
                }
            }
        }
    }

    cout<<"NO"<<endl;
    return 0;
}

