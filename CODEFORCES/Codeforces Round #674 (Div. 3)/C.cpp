#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST
    int t;
    cin>>t;

    while(t--)
    {

        ll n;
        cin>>n;

        ll m = sqrt(n);

        ll m2 = n/m;

        ll step = m-1+m2-1;

        ll got = m*m2;

        if(got==n)
            cout<<step<<endl;
        else
            cout<<step+1<<endl;

    }

    return 0;
}

