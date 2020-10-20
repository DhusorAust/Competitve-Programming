#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///**************

vector <int> V[200];

int color[200];

queue <int > q;
int ans[200];

void BFS(int s)
{
    color[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

      //  cout<<u<<" ";

        int v;
        for(int i=0;i<V[u].size();i++)
        {
            v = V[u][i];
            if(color[v]==0)
            {
                q.push(v);
                color[v] = 1;
                if(ans[u]==2)
                    ans[v] = 1;
                else if(ans[u]==1)
                    ans[v] = 2;

            }
        }
    }
}

///***********

int main()
{
    FAST

    int t;

    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            V[i].clear();
            ans[i] = 0;
            color[i] = 0;
        }

        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;

            V[u].push_back(v);
            V[v].push_back(u);
        }
        ans[1] = 2;
        BFS(1);

        for(int i = 1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}

