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

        string s1,s2;
        cin>>s1>>s2;

        bool bol = false;

        for(ll  i =0;i<n;i++)
        {
            if(s1[i]>s2[i])
            {
                bol = true;
                break;
            }
        }

        if(bol)
        {
            cout<<"-1"<<endl;
            continue;
        }

        ll cnt = 0;
        for(char c = 'a';c<'t';c++)
        {
            char miin = 'z';
            vector<ll> v;
            for(ll i = 0;i<n;i++)
            {
                if(s1[i]==c && s1[i]!=s2[i])
                {
                    miin = min(miin,s2[i]);
                    v.push_back(i);
                }
            }

            if(miin =='z')
                continue;

            for(ll i = 0;i<v.size();i++)
            {
                s1[v[i]] = miin;
            }
            cnt++;
        }

        cout<<cnt<<endl;
    }

    return 0;
}
