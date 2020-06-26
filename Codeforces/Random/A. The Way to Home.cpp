#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
int ans[200];
int main()
{
    FAST;

    ll n,d;
    cin>>n>>d;
    string s;
    cin>>s;
    bool found = true;
    for(int i=1;i<n;i++)
    {

        if(s[i]=='1')
        {
            found = false;
            for(int j = 0;j<i;j++)
            {
                if(i-j<=d && s[j]=='1')
                {
                    ans[i] = ans[j]+1;
                    found = true;
                    break;
                }
            }
        }
        if(!found)
        {
            cout<<"-1"<<endl;
            break;
        }
    }

    /*for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";*/
    if(found)
        cout<<ans[n-1]<<endl;





    return 0;
}
