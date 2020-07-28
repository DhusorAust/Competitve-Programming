#include<bits/stdc++.h>
using namespace std;

int color[20009];
int p[20009];
queue <int > q;
int n,m;

void BFS(int s)
{
    color[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u>1)
        {
            int v = u-1;
            if(color[v]==0)
            {
                q.push(v);
                color[v] = 1;
                p[v] = p[u]+1;
            }
        }
        if(u<m)
        {
            int v = 2*u;
            if(color[v]==0)
            {
                q.push(v);
                color[v] = 1;
                p[v] = p[u]+1;
            }
        }

    }
}

int main()

{
    cin>>n>>m;
    p[n] = 0;
    BFS(n);
    cout<<p[m]<<endl;

    return 0;
}
