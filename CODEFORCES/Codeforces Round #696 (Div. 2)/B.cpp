
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int isPrime[100009];
vector<int> prime;
void sieve(int n)
{
    isPrime[2] = 1;
    for(int i=3;i<=n;i+=2)
        isPrime[i] = 1;
    for (int p=3; p*p<=n; p+=2)
    {
        if (isPrime[p] == 1)
        {
            for (int i=p*p; i<=n; i += 2*p)
                isPrime[i] = 0;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(isPrime[i])
            prime.push_back(i);
    }
}
int main()
{
    sieve(100005);
    ll t;
    cin>>t;
    while(t--)
    {
        ll d;
        cin>>d;
        vector<ll> ans;
        ans.push_back(1);
        ll cnt = 2;
        ll last = 1;
        for(int i=0;i<prime.size();i++)
        {
            if(cnt==4)
                break;
            if(prime[i]-last>=d)
            {
                ans.push_back(prime[i]);
                cnt++;
                last= prime[i];
            }
        }
        ll ans2 = 1;

        for(ll i = 0;i<ans.size();i++)
        {
            //cout<<ans[i]<<" ";
            ans2*=ans[i];
        }
        cout<<ans2<<endl;

    }


    return 0;
}
