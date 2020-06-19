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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int zero  = 0;
        int ans = 0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                v.push_back(i);
        }
        if(v.size()==0)
        {
            ans = n/(k+1);
            if(n%(k+1)!=0)
                ans++;
            cout<<ans<<endl;
            continue;
        }
        else
        {
            for(int i=1;i<v.size();i++)
            {
                int temp = v[i]-v[i-1]-1;
                temp-=k;
                if(temp>k)
                {
                    ans += temp/(k+1);
                }
            }
            int temp = v[0]-0;
            temp-=k;
            if(temp>=1)
            {
                ans += temp/(k+1);
                if(temp%(k+1)!=0)
                 ans++;
            }
            temp = n-v[v.size()-1]-1;
            temp-=k;
            if(temp>=1)
            {
                ans += temp/(k+1);
                if(temp%(k+1)!=0)
                   ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}