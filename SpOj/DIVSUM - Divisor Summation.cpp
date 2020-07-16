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

ll SOD(ll n)

 {
    ll sqrtn = sqrt(n);
    ll product = 1;
    for(ll i = 0; i<prime.size() && prime[i]<=sqrtn;i++)
    {
        if(n%prime[i]==0)
        {
            ll temp = 1;
            while(n%prime[i]==0)
            {
                n = n/prime[i];
                temp*=prime[i];
            }
            temp = temp*prime[i];
            temp = (temp-1)/(prime[i]-1);
            product = product*temp;
        }
        sqrtn = sqrt(n);
    }
    if(n!=1)
     {
        ll temp = n*n;
        temp = (temp-1)/(n-1);
        product = product*temp;
     }
     return product;
 }

int main()

{
        sieve(500);

        ll t;
        cin>>t;

        while(t--)
        {
              ll n;
              cin>>n;
             cout<<SOD(n)-n<<endl;
        }



       return 0;
}
