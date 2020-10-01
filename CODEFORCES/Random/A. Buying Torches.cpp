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
        ll x,y,k;
        cin>>x>>y>>k;

        ll coalstick = y*k;
        ll totstick = coalstick+k;

        ll step = 0;

        ll ache = 1;


        if(totstick>ache)
        {

           step++;
           ache = x;

           ll dorkar = totstick - ache;

           step+= (dorkar/(x-1));

           if( (step-1)*(x-1)+x <totstick)
            step++;
        }

        cout<<step+k<<endl;



    }

    return 0;
}

/*
1
42 13 24


*/

