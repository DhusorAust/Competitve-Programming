#include<bits/stdc++.h>
using namespace std;
int const N = 100009;
vector<int> V[N];
int color[N];
priority_queue<int, vector<int>, greater<int> > q;
void BFS(int s)
{
    color[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.top();
        q.pop();

        cout<<u<<" ";

        int v;
        for(int i=0;i<V[u].size();i++)
        {
            v = V[u][i];
            if(color[v]==0)
            {
                q.push(v);
                color[v] = 1;
            }
        }
    }
}
int main()
{
    int n,E;
    cin>>n>>E;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    BFS(1);
    cout<<endl;

    return 0;
}

