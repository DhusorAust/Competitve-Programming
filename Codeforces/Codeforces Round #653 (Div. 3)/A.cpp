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
       ll x,y,n;
       cin>>x>>y>>n;

       ll temp = n/x;
       ll temp2 = temp*x;

       if(n-temp2<y)
          temp2-=x;
       cout<<temp2+y<<endl;



    }

    return 0;
}

