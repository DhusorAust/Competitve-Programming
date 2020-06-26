#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {

        ll a,b,c;
        cin>>a>>b>>c;

        if(a*b<c)
        {
            cout<<1<<" "<<-1<<endl;
        }
        else if(a*b==c)
        {
            cout<<1<<" "<<-1<<endl;
        }
        else
        {
            if(a>=c)
                cout<<-1<<" "<<b<<endl;
            else
                cout<<1<<" "<<b<<endl;

        }




    }
    return 0;
}
