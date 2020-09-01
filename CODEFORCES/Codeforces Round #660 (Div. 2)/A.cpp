#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;



        ll sum1 = 6+10+14;
        ll sum2 = 6+10+15;
       // ll sum3 = 10+14+15;
        //ll sum4 = 6+14+15;


        if(n>sum1 && n-sum1 !=6 && n-sum1!=10 && n-sum1!=14)
        {
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<14<<" "<<n-sum1<<endl;
            continue;
        }
        if(n>sum2 && n-sum2!=6 && n-sum2!=10 && n-sum2!=15)
        {
            cout<<"YES"<<endl;
            cout<<6<<" "<<10<<" "<<15<<" "<<n-sum2<<endl;
            continue;
        }

        cout<<"NO"<<endl;



    }

    return 0;
}

