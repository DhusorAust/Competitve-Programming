#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
#define pb push_back

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll arr[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n);

        bool bol = false;
        for(ll i = 0;i<n-1;i++)
        {
            if(arr[i+1]-arr[i]>1)
            {

                bol =  true;
                break;
            }
        }

        if(bol)
            cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;




    }

    return 0;
}

