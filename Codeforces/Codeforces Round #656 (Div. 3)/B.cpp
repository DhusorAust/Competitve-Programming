
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
        ll arr[2*n];

        for(ll i=0;i<2*n;i++)
            cin>>arr[i];

        map<ll,ll> m;
        for(ll i=0;i<2*n;i++)
        {
            if(m[arr[i]]==0)
            {
                cout<<arr[i]<< " ";
                m[arr[i]]++;
            }
        }

        cout<<endl;




    }

    return 0;
}

