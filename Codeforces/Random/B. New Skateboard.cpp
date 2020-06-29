#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int main()
{
    FAST;
    string s;
    cin>>s;
    ll n = s.length();
    ll sum = 0;
    for(ll i=0;i<n;i++)
    {
        ll tmp = s[i]-48;
        if(tmp%4==0)
            sum++;
    }
    for(ll i=1;i<n;i++)
    {
        ll tmp = (s[i]-48)+ (s[i-1]-48)*10;
        if(tmp%4==0)
            sum+= i;
    }
    cout<<sum<<endl;
    return 0;
}
