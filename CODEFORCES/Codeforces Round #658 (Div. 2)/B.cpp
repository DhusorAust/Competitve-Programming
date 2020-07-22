
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

        ll arr[n];

        for(ll i = 0;i<n;i++)       
            cin>>arr[i];
        
        ll cnt = 0;      

        for(ll i=0;i<n-1;i++)
        {
            if(arr[i]!=1)               
                break;           
            cnt++;
        }

        ll cnt2 = 1;

        if(cnt%2!=0)
            cnt2 = 1- cnt2;

        if(cnt2==1)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }

    return 0;
}

