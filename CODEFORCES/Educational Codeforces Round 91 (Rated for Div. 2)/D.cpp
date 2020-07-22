#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
ll F[200009];
int main()
{
    FAST

    ll n,m;
    cin>>n>>m;

    ll x,k,y;
    cin>>x>>k>>y;

    ll arr1[n+2],arr2[m+2];

    arr1[0] = -1;
    arr1[n+1] = -1;

    for(ll i=1;i<=n;i++)
    {
        cin>>arr1[i];
    }

    for(ll i=1;i<=m;i++)
    {
        cin>>arr2[i];
    }


    vector<ll> v;
    v.push_back(0);

    ll j,i;

    for(i=1,j =1;i<=n;i++)
    {
        if(arr1[i]==arr2[j])
        {
            j++;
            v.push_back(i);
        }
    }

    if(j!=m+1)
    {
        cout<<-1<<endl;
        return 0;
    }

    v.push_back(n+1);

    ll ix = 1;
    ll N = v.size()-1;

    for(i=0,j=1;j<v.size();i++,j++)
    {
        ll I = v[i];
        ll J = v[j];
        ll range  = J-I-1;

        for(ll l = I+1;l<J;l++)
        {
            if(arr1[l]>arr1[I]&& arr1[l]>arr1[J])
            {
                if(range<k)
                {
                    cout<<-1<<endl;
                    return 0;
                }
                F[ix] = 1;
            }
        }
        ix++;
    }

    ll sum = 0;
    for(int i=1;i<=N;i++)
    {
        ll range  = v[i]-v[i-1]-1;
        ll rem = range %k;

       if(x<=k*y)
       {
           sum+= range/k*x+rem*y;
       }
       else
       {
           if(F[i]==0)
                sum+= range*y;
           else
               sum+= x+(range-k)*y;
       }
    }

    cout<<sum<<endl;

    return 0;
}

