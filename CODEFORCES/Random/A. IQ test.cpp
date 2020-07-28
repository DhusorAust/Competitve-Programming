#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll n;
    cin>>n;

    ll arr[n];

    ll cnt1 = 0, cnt2  = 0;
    for(ll i = 0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2==0)
            cnt1++;
        else
           cnt2++;
    }

    if(cnt1>cnt2)
    {
        for(ll i = 0;i<n;i++)
        {

            if(arr[i]%2!=0)
            {
                cout<<i+1<<endl;
                return 0;
            }

        }
    }
    else
    {
        for(ll i = 0;i<n;i++)
        {

            if(arr[i]%2==0)
            {
                cout<<i+1<<endl;
                return 0;
            }

        }
    }



    return 0;
}

