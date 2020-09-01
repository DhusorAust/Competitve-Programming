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
        ll a, b;
        cin>>a>>b;

        if(a<b)
        {
            ll cnt = 0;
            while(a<b)
            {
                a*=2;
                cnt++;
            }
            if(a==b)
            {
                ll ans = cnt/3;
                cnt = cnt%3;
                ans+=cnt/2;
                cnt%=2;
                ans+=cnt;
                cout<<ans<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
        else
        {
            ll cnt = 0;
            while(a>b)
            {
                if(a%2==0)
                    a/=2;
                else
                    break;

                cnt++;
            }
            if(a==b)
            {
                ll ans = cnt/3;
                cnt = cnt%3;
                ans+=cnt/2;
                cnt%=2;
                ans+=cnt;
                cout<<ans<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
    }

    return 0;
}

