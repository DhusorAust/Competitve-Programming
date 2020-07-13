#include <bits/stdc++.h>
using namespace std;
//#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
   // FAST

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        //cin>>n;
        scanf("%lld",&n);

        ll arr1[n],arr2[n];

        unordered_map<ll,ll> m1,m2;
        set<ll> s;

        ll miin = 100000000000;

        for(ll i = 0;i<n;i++)
        {
            //cin>>arr1[i];
            scanf("%lld",&arr1[i]);
            m1[arr1[i]]++;
            s.insert(arr1[i]);
            miin = min(arr1[i],miin);
        }
        for(ll i = 0;i<n;i++)
        {
            //cin>>arr2[i];
            scanf("%lld",&arr2[i]);
            m2[arr2[i]]++;
            s.insert(arr2[i]);
            miin = min(arr2[i],miin);
        }

        set<ll> :: iterator it2;

        bool bol = false;

        for(it2 = s.begin();it2!=s.end();it2++)
        {
            ll val = m1[*it2]+m2[*it2];
            if(val%2!=0)
            {
                bol = true;
                break;
            }
        }

        if(bol)
        {
            //cout<<-1<<endl;
            printf("-1\n");
            continue;
        }
        vector<ll> v;

        for(it2 = s.begin();it2!=s.end();it2++)
        {
            ll half = (m1[*it2]+m2[*it2])/2;
            for(ll i = m1[*it2];i<half;i++)
            {
                v.push_back(*it2);
            }

            for(ll i = m2[*it2];i<half;i++)
            {
                v.push_back(*it2);
            }
        }

        sort(v.begin(),v.end());


        ll sum = 0;
        ll m = v.size()/2;
        for(ll i = 0;i<m;i++)
        {
            if(miin*2>v[i])
                sum+=v[i];
            else
                sum+= miin*2;
        }

        printf("%lld\n",sum);

    }

    return 0;
}


