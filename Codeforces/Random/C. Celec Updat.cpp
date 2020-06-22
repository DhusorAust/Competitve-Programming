#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll l = x2-x1+1;
        ll w = y2-y1+1;
        ll A =l*w;
        ll ans = A-l-w+2;
        cout<<ans<<endl;
    }
    return 0;
}
