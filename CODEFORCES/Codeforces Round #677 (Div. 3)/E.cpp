#include<bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    ll n;
    cin>>n;

    ll fct = 1;
    for(ll i=1;i<=n;i++)
        fct*=i;

    cout<<fct/n/(n/2)<<endl;

    return 0;
}

