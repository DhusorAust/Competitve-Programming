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
        
        ll arr[n+5];
        vector<int> v[n+5];

        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        for(int i=0;i<=n;i++)
            v[i].push_back(-1);
        
        for(int i=0;i<n;i++)
            v[arr[i]].push_back(i);
        

        for(int i=0;i<=n;i++)
            v[i].push_back(n);
        
        int ans[n+5];
        memset(ans,-1,sizeof(ans));

        for(int i=0;i<=n;i++)
        {  
            int maax = INT_MIN;
            
            for(int j=1;j<v[i].size();j++)
                maax = max(maax, v[i][j]-v[i][j-1]);
            
            if(ans[maax]==-1)
                ans[maax] = i;
        }

        for(int i=1;i<=n;i++)
        {
             if(ans[i]>ans[i-1] && ans[i-1]!=-1)
                ans[i] = ans[i-1];
             else if(ans[i]==-1)
                ans[i] = ans[i-1];
        }
        
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
            
        cout<<endl;

    }
    return 0;
}
