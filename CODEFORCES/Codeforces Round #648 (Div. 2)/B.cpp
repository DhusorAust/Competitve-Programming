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

        ll A[n],B[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>A[i];
        }

        bool bol1 = false, bol2 = false;
        for(ll i = 0;i<n;i++)
        {
            cin>>B[i];
            if(B[i]==1)
                bol1 = true;
            if(B[i]==0)
                bol2 = true;
        }

        if(bol1 && bol2)
        {
            cout<<"Yes"<<endl;
            continue;
        }

        bool bol =false;
        for(ll i = 1;i<n;i++)
        {
            if(A[i]<A[i-1])
            {
                bol = true;
                break;
            }
        }

        if(bol)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }

    return 0;
}

