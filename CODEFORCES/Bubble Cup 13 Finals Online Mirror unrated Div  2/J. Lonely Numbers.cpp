#include <bits/stdc++.h>
using namespace std;
int prime[1000009];
void sieve(int n)
{
    prime[1] = 1;
    prime[2] = 1;
    for(int i=3;i<=n;i+=2)
        prime[i] = 1;
    for (int p=3; p*p<=n; p+=2)
    {
        if (prime[p] == 1)
        {
            for (int i=p*p; i<=n; i += 2*p)
                prime[i] = 0;
        }
    }
}

int main()
{
    sieve(1000005);
    for(int i=1;i<=1000005;i++)
       prime[i] += prime[i-1];

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int m = sqrt(n);
        //cout<<prime[n]-prime[m]+1<<endl;
        printf("%d\n",prime[n]-prime[m]+1);
    }
    return 0;
}

