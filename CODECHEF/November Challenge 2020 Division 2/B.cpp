#include <bits/stdc++.h>
using namespace std;
int isPrime[100000000];
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
    sieve(4000000);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int arr[n+9],ans[n+9];
        vector<int> v[n+9];

        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            v[arr[i]].push_back(i);
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                ans[v[i][j]] = prime[i];
            }
        }

        for(int i=1;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<ans[n]<<endl;
    }

    return 0;
}
