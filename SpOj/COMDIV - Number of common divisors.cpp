
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll status[100000000/32];
vector<ll> prime;

bool Check(ll N,ll pos)
{
    return (bool)(N & (1<<pos));
}
ll Set(ll N,ll pos)
{
    return N=N | (1<<pos);
}
void sieve(ll  N)
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

ll NOD(ll n)
{
    ll  sqrtn = sqrt(n);
    ll product = 1;
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
            product = product*(cnt+1);
        }
        sqrtn = sqrt(n);
    }
    if(n!=1)
        product = product*2;
    return product;
}

int main()
{
    sieve(1000);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll  a,b;
        scanf("%lld%lld",&a,&b);

        ll gcd = __gcd(a,b);
        printf("%lld\n",NOD(gcd));
    }
    return 0;
}
