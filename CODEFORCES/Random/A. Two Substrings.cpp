#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    string s;
    cin>>s;

    ll n = s.size();

    ll cnt[n],cnt2[n];

    cnt[0] = 0;
    cnt2[0] = 0;

    for(ll i = 1;i<n;i++)
    {
        if(s[i-1]=='A'&& s[i]=='B')
            cnt[i] = 1;
        else
            cnt[i] = 0;

        cnt2[i] = cnt[i];
    }



    for(ll i = 1;i<n;i++)
    {
       cnt[i]+=cnt[i-1];
    }

    for(ll i = n-2;i>=0;i--)
    {
       cnt2[i]+= cnt2[i+1];
    }

    for(ll i = 1;i<n;i++)
    {
        if(s[i-1]=='B'&& s[i]=='A')
        {
            ll I = i+2;
            if(I<n && cnt2[I]!=0)
            {
                cout<<"YES"<<endl;
                return 0;
            }

            I = i-2;
            if(I>=0 && cnt[I]!=0)
            {
                cout<<"YES"<<endl;
                return 0;
            }

        }

    }

    cout<<"NO"<<endl;

    return 0;
}

