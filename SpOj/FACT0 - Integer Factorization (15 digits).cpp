#include<bits/stdc++.h>

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
vector<ll> prime,P,E;

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

bool isPrime(ll a)
{
    if(a<2)
        return false;
    if(a==2)
        return true;
    if(a%2==0)
        return false;
    if(Check(status[a/32],a%32)==0)
        return true;
    return false;
}
void decomp(ll n)
{
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
                P.push_back(prime[i]);
                E.push_back(cnt);
            }
        }
        sqrtn = sqrt(n);
    }
    if(n!=1)
    {
        P.push_back(n);
        E.push_back(1);
    }
}

int main()
{

        sieve(100000000);
        while(true)
        {
            P.clear();
            E.clear();

            ll n;
            cin>>n;
            if(n==0)
                break;

            decomp(n);

            for(ll i=0;i<P.size()-1;i++)
            {
                    cout<<P[i]<<"^"<<E[i]<<" ";
            }
            cout<<P[P.size()-1]<<"^"<<E[P.size()-1]<<endl;
        }

    return 0;
}

