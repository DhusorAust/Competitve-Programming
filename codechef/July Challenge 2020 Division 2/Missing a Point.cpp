#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll m = 4*n-1;

        map<ll,ll> mx,my;

        for(ll i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;

            mx[x]++;
            my[y]++;
        }

        map<ll,ll> :: iterator it;

        ll div = 2;

        ll X,Y;

        for(it=mx.begin();it!=mx.end();it++)
        {

           ll val = it->second;

           if(val%div!=0)
           {
               X = it->first;
               break;
           }
        }

        for(it=my.begin();it!=my.end();it++)
        {

           ll val = it->second;

           if(val%div!=0)
           {
               Y = it->first;
               break;
           }
        }

        cout<<X<<" "<<Y<<endl;

    }

    return 0;
}

