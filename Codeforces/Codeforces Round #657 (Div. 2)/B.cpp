#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll l,r,m;
        cin>>l>>r>>m;

        if(m>r)
        {
            ll ans = 10000000000000;
            ll ans2 = 10000000000000;

            ll I1,I2;

            for(ll i = l; i<=r;i++)
            {
               ll rem = m%i;
               ll rem2 = i-rem;

               if(rem<ans)
               {
                   I1 = i;
                   ans = rem;
               }

               if(rem2<ans2)
               {
                   I2 = i;
                   ans2 = rem2;
               }
            }

            ll a,b,c;

            if(ans<ans2)
            {
                c = r-ans;
                b = r;
                a = I1;
            }
            else
            {
                c = l+ans2;
                b = l;
                a = I2;
            }

            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else if(m<l)
        {
            ll tmp = l-m;
            ll a = l;
            ll b = l;
            ll c = l+tmp;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else
             cout<<m<<" "<<l<<" "<<l<<endl;
    }

    return 0;
}



