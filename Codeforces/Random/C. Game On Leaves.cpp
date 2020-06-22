#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,E;
        cin>>n>>x;
        E = n-1;
        int cnt = 0;
        string s,A,B;
        A = "Ayush";
        B = "Ashish";
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            if(u==x || v==x)
            {
                cnt++;
            }
        }
        if(cnt==1 || n ==1)
        {
            s = A;
        }
        else
        {
            int node  = n-cnt-1;
            if(node%2==cnt%2)
            {
                s = B;
            }
            else
            {
                s = A;
            }
        }
        cout<<s<<endl;
    }
}
