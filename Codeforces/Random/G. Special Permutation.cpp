#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<=3)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int m = n;
        if(m%2==0)
            m--;
        for(int i = m;i>=1;i-=2)
            cout<<i<<" ";
        cout<<"4 2";
        for(int i=6;i<=n;i+=2)
            cout<<" "<<i;
        cout<<endl;
    }
    return 0;
}
