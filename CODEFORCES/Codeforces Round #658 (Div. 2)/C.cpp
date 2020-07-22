
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

string s1,s2;
void f(ll n)
{
    for(ll i=0;i<n;i++)
    {
        if(s1[i]=='0')
            s1[i] = '1';
        else
            s1[i] = '0';
    }

    for(ll i=0, j=n-1;i<n/2;i++,j--)
    {
        swap(s1[i],s1[j]);
    }
}
int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;


        cin>>s1>>s2;

        vector<ll> v;
        for(ll i = n-1;i>=0;i--)
        {

            if(s2[i]==s1[0])
            {
                v.push_back(1);
                f(1);
                v.push_back(i+1);
                f(i+1);    
            }
            else
            {
                v.push_back(i+1);            
                f(i+1);
            }     
            if(s1==s2)
                break;
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

