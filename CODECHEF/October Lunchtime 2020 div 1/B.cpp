#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);



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
        FAST
        sieve(400);//will work upto 10000^2
      /*  while(true)
        {
            P.clear();
            E.clear();

            ll n;
            cin>>n;
            decomp(n);

            for(ll i=0;i<P.size();i++)
            {
                for(ll j = 0;j<E[i];j++)
                {
                    cout<<P[i]<<" ";
                }
            }
            cout<<endl;
        }*/

         ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        ll arr[n];


        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        vector<int> v[n];

        for(ll i=0;i<n;i++)
        {
            P.clear();
            E.clear();
            decomp(arr[i]);
            for(ll j=0;j<P.size();j++)
            {
                v[i].push_back(P[j]);
            }
        }

     /*   for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }*/

        set<int> s[n],s2[n];
        for(int i=0;i<v[0].size();i++)
        {
            s[0].insert(v[0][i]);
        }

        for(int i=0;i<v[n-1].size();i++)///
        {
            s2[n-1].insert(v[n-1][i]);
        }

        for(int i=1;i<n;i++)
        {
            for(auto it = s[i-1].begin();it!=s[i-1].end();it++)
            {
                s[i].insert(*it);
            }

            for(int j=0;j<v[i].size();j++)
            {
                s[i].insert(v[i][j]);
            }
        }

         for(int i=n-2;i>=0;i--)///
        {
            for(auto it = s2[i+1].begin();it!=s2[i+1].end();it++)
            {
                s2[i].insert(*it);
            }

            for(int j=0;j<v[i].size();j++)
            {
                s2[i].insert(v[i][j]);
            }
        }

      /*  for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
            for(auto j=s[i].begin();j!=s[i].end();j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
        */
        /*for(int i=1;i<n;i++)
        {
            if(f(dp[i-1],dp[n-1]/dp[i-1]))
            {
                cout<<i<<endl;
                break;
            }
        }*/

        for(int i=0;i<n-1;i++)
        {
            bool bol = false;
            for(auto it = s[i].begin();it!=s[i].end();it++)
            {
                for(auto it2 = s2[i+1].begin();it2!=s2[i+1].end();it2++)
                {
                    if(*it ==*it2)
                    {
                        bol = true;
                        break;
                    }
                }
                if(bol)
                    break;
            }
            if(bol == false)
            {
                cout<<i+1<<endl;
                break;
            }


        }


    }
    return 0;
}
