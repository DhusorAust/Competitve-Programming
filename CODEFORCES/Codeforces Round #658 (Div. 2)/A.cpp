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
        ll n,m;
        cin>>n>>m;

        ll arr[n],arr2[m];

        map<ll,ll> M;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            M[arr[i]] = 1;
        }

        ll ans = INT_MIN;
        for(int i=0;i<m;i++)
        {
            cin>>arr2[i];
            if(M[arr2[i]]==1)
            {
                ans = arr2[i];
            }
        }

        if(ans==INT_MIN)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<1<<" "<<ans<<endl;
        }
    }

    return 0;
}

