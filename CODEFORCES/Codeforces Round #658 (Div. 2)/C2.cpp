
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

string s1,s2;
ll cnt = 0;

char invert(char c)
{
    if(c == '1')
        return '0';
     return '1';
}

char actual(char c)
{
    if(cnt%2==0)
        return c;
    return invert(c);
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        cnt = 0;
        
        ll n;
        cin>>n;
        cin>>s1>>s2;
        
        vector<ll> v;
        ll Front = 0;
        ll Back = n-1;
        
        for(ll i = n-1,j=0;i>=0;i--,j++)
        {
            ll tmp;
            if(j%2==0)
               tmp = Front++;
            else
                tmp = Back--;
               
            if(s2[i]==actual(s1[tmp]))
            {
                v.push_back(1);
                s1[tmp] = invert(actual(s1[tmp]));
                v.push_back(i+1);
            }
            else
            {
                v.push_back(i+1);
            }
            cnt++;
        }
        
        cout<<v.size();
        
        for(int i=0;i<v.size();i++)
        {
            cout<<" "<<v[i];
        }
        cout<<endl;
    }
    return 0;
}

