#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        ll step   = 0;
        ll mx = max(a,b);
        ll mn = min(a,b);
        for(;;step++)
        {
            ll temp = mn;
            mn = mx;
            mx += temp;
            if(mn >n && mx>n)
                break;
        }
        cout<<step<<endl;
    }
    return 0;
}
