#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
int main()
{
        sieve(1000009);
        ll t;
        scanf("%lld",&t);
        while(t--)
        {
            ll n;
            scanf("%lld",&n);
            ll m = sqrt(n);
            ll L = upper_bound(prime.begin(),prime.end(),m)-prime.begin();
            ll L2 = upper_bound(prime.begin(),prime.end(),n)-prime.begin();
            L--;
            L2--;
            printf("%lld\n",L2-L+1);
        }
    return 0;
}
