
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
string s;

ll f(ll i,ll j,char c)
{
    if(i==j)
        {
            if(s[i]==c)
                return 0;
            else
                return 1;
        }
    char c2 = c+1;
    ll cnt1 = 0,cnt2 = 0;
    ll m = (j-i+1)/2;
    for(ll k=0,l = i;k<m;k++,l++)
    {
        if(s[l]!=c)
            cnt1++;
    }
  
    ll ans1 =  f(i,i+m-1,c2);

    for(ll k=0,l = i+m;k<m;k++,l++)
    {
       
         if(s[l]!=c)
            cnt2++;
    }
  

    ll ans2 = f(i+m,j,c2);

    return min(ans1+cnt2,ans2+cnt1);
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {

        ll n;
        cin>>n;
        cin>>s;

        cout<<f(0,n-1,'a')<<endl;
    }

    return 0;
}

