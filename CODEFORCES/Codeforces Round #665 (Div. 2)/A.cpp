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
        ll n,k;
        cin>>n>>k;
        if(n>=k)
        {
            if(k%2==n%2)
                cout<<0<<endl;
            else
                cout<<1<<endl;
        }
        else
            cout<<k-n<<endl;
    }
    return 0;
}

