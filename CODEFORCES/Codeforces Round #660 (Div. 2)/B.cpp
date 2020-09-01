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
        ll n;
        cin>>n;

        ll tmp = n/4;
        if(n%4!=0)
            tmp++;

        for(ll i = 0;i<n-tmp;i++)
        {
            cout<<"9";
        }
        for(ll i = 0;i<tmp;i++)
        {
            cout<<"8";
        }
        cout<<endl;
    }

    return 0;
}

