#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

struct node
{
    ll t,a,b;
};

bool cmp(node a, node b)
{
    return a.t<b.t;
}

int main()
{
    FAST

    ll n,k;
    cin>>n>>k;

    node arr[n];

    vector<ll> v1,v2,v3;

    for(ll i=0;i<n;i++)
    {
        ll t,a,b;
        cin>>t>>a>>b;

        arr[i].t = t;
        arr[i].a = a;
        arr[i].b = b;
    }

    sort(arr,arr+n,cmp);

    for(ll i=0;i<n;i++)
    {
        if(arr[i].a ==1 && arr[i].b ==0)
        {
            v1.push_back(arr[i].t);
        }
        if(arr[i].a ==0 && arr[i].b ==1)
        {
            v2.push_back(arr[i].t);
        }
        if(arr[i].a ==1 && arr[i].b ==1)
        {
            v3.push_back(arr[i].t);
        }
    }
    ll n1,n2,n3;
    n1 = v1.size();
    n2 = v2.size();
    n3 = v3.size();

    if(n1 + n3 <k || n2+n3 <k)
    {
        cout<<-1<<endl;
        return 0;
    }

    ll i = 0,j = 0,kk =0;
    ll cnt1 = 0, cnt2 =0;
    ll sum = 0;
    for(;;)
    {
        if(cnt1 ==k )
            break;
        ll tmp1 = 10000000000;
        ll tmp2 = 10000000000;
        ll tmp3 = 10000000000;

        if(i<n1)
             tmp1 = v1[i];
        if(j<n2)
             tmp2 = v2[j];
        if(kk<n3)
             tmp3 = v3[kk];

        if(tmp1+tmp2<=tmp3)
        {
            i++;
            j++;
            sum+=tmp1+tmp2;
            cnt1++;
            cnt2++;
        }
        else
        {
            kk++;
            sum+=tmp3;
            cnt1++;
            cnt2++;
        }
    }

    cout<<sum<<endl;
    return 0;
}

