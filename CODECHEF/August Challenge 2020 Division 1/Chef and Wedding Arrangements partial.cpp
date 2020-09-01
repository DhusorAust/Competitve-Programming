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

        ll arr[n];
        vector<ll> v[n];

        for(ll i = 0;i<n;i++)
        {
            cin>>arr[i];
            v[i].push_back(arr[i]);
        }

        ll sum = 0;

        for(ll i = 1;i<n-1;i++)
        {
            vector<ll> v2,v3;

            for(ll j = 0;j<v[i-1].size();j++)
            {
                v2.push_back(v[i-1][j]);
            }

            for(ll j = 0;j<v[i].size();j++)
            {
                v2.push_back(v[i][j]);
                v3.push_back(v[i][j]);

            }

            for(ll j = 0;j<v[i+1].size();j++)
            {
                v3.push_back(v[i+1][j]);
            }



            ll m[101],m2[101];
            memset(m,0,sizeof(m));
            memset(m2,0,sizeof(m2));
            for(ll j = 0;j<v2.size();j++)
            {
                m[v2[j]]++;
            }

            for(ll j = 0;j<v3.size();j++)
            {
                m2[v3[j]]++;
            }

            ll cnt = 0;

            for(ll j =0;j<101;j++)
            {
                if(m[j]>=2)
                    cnt+=m[j];
            }

            ll cnt2 = 0;
            for(ll j =0;j<101;j++)
            {
                if(m2[j]>=2)
                    cnt2+=m2[j];
            }

            if(cnt<=cnt2)
            {
                if(cnt<k)
                {
                    v[i-1].clear();
                    v[i].clear();
                    v[i] = v2;
                }
            }
            else
            {
                if(cnt2<k)
                {
                    v[i+1].clear();
                    v[i].clear();
                    v[i+1] = v3;
                }
            }
        }
        ll m[101];
        memset(m,0,sizeof(m));

            vector<ll> v2;

            for(ll j = 0;j<v[n-1].size();j++)
            {
                v2.push_back(v[n-1][j]);
            }

            if(n!=1)
            {
                for(ll j = 0;j<v[n-2].size();j++)
                {
                    v2.push_back(v[n-2][j]);
                }
            }
            for(ll j = 0;j<v2.size();j++)
            {
                m[v2[j]]++;
            }

            ll cnt = 0;

            for(ll j =0;j<101;j++)
            {
                if(m[j]>=2)
                    cnt+=m[j];
            }
             if(cnt<k)
                {
                    v[n-1].clear();
                    v[n-2].clear();
                    v[n-2] = v2;
                }

     /*   for(int i =0;i<n;i++)
        {
            cout<<i<<endl;
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        */

        for(ll i = 0;i<n;i++)
        {
            ll m[101];
            memset(m,0,sizeof(m));

            for(ll j = 0;j<v[i].size();j++)
            {
                m[v[i][j]]++;
            }

            ll cnt = 0;

            for(ll j =0;j<101;j++)
            {
                if(m[j]>=2)
                    cnt+=m[j];
            }
            if(v[i].size()!=0)
                sum+=k+cnt;
        }

        cout<<sum<<endl;

    }

    return 0;
}

