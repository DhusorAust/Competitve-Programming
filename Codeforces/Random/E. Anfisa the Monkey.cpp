#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll k, a, b;
    cin>>k>>a>>b;

    string s;
    cin>>s;

    ll n = s.length();

    if(k*a>n || k*b<n)
    {
        cout<<"No solution"<<endl;
        return 0;
    }

    ll ans[k];
    ll sum = 0;
    for(int i = 0;i<k;i++)
    {
        ans[i] = a;
        sum+=a;
    }
    for(int i = 0;i<k;i++)
    {
        if(sum==n)
            break;
        ll tmp1 = b-a;
        ll tmp2 = n-sum;
        ans[i]+=min(tmp1,tmp2);
        sum+= min(tmp1,tmp2);
    }
    int l = 0;
    for(int i = 0;i<k;i++)
    {
        for(int j=0;j<ans[i];j++,l++)
        {
            cout<<s[l];
        }
        cout<<endl;
    }


}
