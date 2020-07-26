#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
#define pb push_back
char change(char c)
{
    if(c=='a')
        return 'b';
    return 'a';
}
int main()
{
    FAST
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll arr[n+1];
        for(ll i = 1;i<=n;i++)
            cin>>arr[i];
        string s[n+1];
        for(ll i = 0;i<=n;i++)
        {
            for(ll j = 0;j<200;j++)
            {
                s[i].pb('a');
            }
        }
        for(ll i = 1;i<=n;i++)
        {
            for(ll j =0;j<arr[i];j++)
            {
                s[i][j] = s[i-1][j];
            }
            s[i][arr[i]] = change(s[i-1][arr[i]]);
        }
        for(ll i = 0;i<=n;i++)
            cout<<s[i]<<endl;
    }
    return 0;
}
