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
        ll l,r;
        cin>>l>>r;

        if(2*l<=r)
        {
            cout<<l<<" "<<2*l<<endl;
        }
        else
        {
            cout<<"-1 -1"<<endl;
        }
    }

    return 0;
}

