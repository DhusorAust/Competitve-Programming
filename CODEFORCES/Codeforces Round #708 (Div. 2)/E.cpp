#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;

bool Check(ll N,ll pos)
{
    return (bool)(N & (1<<pos));
}
ll Set(ll N,ll pos)
{
    return N=N | (1<<pos);
}

ll status[100000000/32];
vector<ll> prime;

void sieve(ll N)
{
    ll i, j, sqrtN;
    sqrtN = ll( sqrt( N ) );
	for( i = 3; i <= sqrtN; i += 2 )
	{
		if( Check(status[i/32],i%32)==0)
		{
			for( j = i*i; j <= N; j += 2*i )
			{
				status[j/32]=Set(status[j/32],j % 32);
			}
		}
	}
	prime.push_back(2);
	for(i=3;i<=N;i+=2)
	{
		 if( Check(status[i/32],i%32)==0)
		 {
			prime.push_back(i);
		 }
	}
}

ll decomp(ll n)
{
    ll num = 1;
    ll sqrtn = sqrt(n);
    for(ll i = 0; i<prime.size() && prime[i]<=sqrtn;i++)
    {
        ll cnt = 0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n = n/prime[i];
            }
            if(cnt>0)
            {
                if(cnt%2==1)
                    num *= prime[i];
            }
        }
        sqrtn = sqrt(n);
    }
    if(n!=1)
    {
        num*=n;
    }
    return num;
}
int main()
{
    FAST
    sieve(3162);
    ll t;
    cin>>t;
    while(t--)
    {
        map< ll,ll > m;
        ll n, k;
        cin>>n>>k;
        ll arr[n];
        for(ll i = 0;i<n;i++)
            cin>>arr[i];
        for(ll i = 0;i<n;i++)
           arr[i] = decomp(arr[i]);
        ll cnt = 1;
        for(ll i = 0;i<n;i++)
        {
           if(m[arr[i]]==cnt)
             cnt++;
           m[arr[i]] = cnt;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

