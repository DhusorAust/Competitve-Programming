#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int val,ix;
};
bool cmp(node a, node b)
{
    return a.val<b.val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    node arr[n];
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].val;
        arr[i].val = n-arr[i].val;
        m[arr[i].val]++;
        arr[i].ix = i;
    }
    bool bol = true;
    map<int,int>:: iterator it;
    sort(arr,arr+n,cmp);
    int ans[n];
    int k = 1;
    vector<int> v;
    for(it = m.begin(); it!=m.end();it++)
    {
       int a,b;
       a = it->first;
       b = it->second;
       if(b%a!=0)
       {
           bol =false;
           break;
       }
       else
       {
           int temp = b/a;
           while(temp--)
           {
               for(int i=0;i<a;i++)
               {
                   v.push_back(k);
               }
               k++;
           }
       }
    }

    if(bol)
    {
        cout<<"Possible"<<endl;
        for(int i=0;i<n;i++)
        {
           ans[ arr[i].ix ]  = v[i];
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"Impossible"<<endl;
    return 0;
}
