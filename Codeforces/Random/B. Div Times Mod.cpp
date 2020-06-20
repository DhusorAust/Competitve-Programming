#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int ans = INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int a,b;
            a = i;
            b = n/i;
            int temp;
            if(a<k && b<k)
            {
                temp = min(a,b)*k+max(a,b);
            }
            else if (a<k)
            {
                temp = a+b*k;
            }
            else if(b<k)
            {
                temp = a*k+b;
            }
            ans = min(ans,temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}
