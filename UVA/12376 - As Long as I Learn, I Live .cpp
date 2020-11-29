#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

vector <int> V[109];

int color[109];

int arr[109];

queue <int > q;

int last = 0;

int sum = 0;

void BFS(int s)
{
    color[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        last = u;
        sum+=arr[u];

        int v;
        int maax = INT_MIN;
        int vv=-1;
        for(int i=0;i<V[u].size();i++)
        {
            v = V[u][i];
            if(arr[v]>maax && color[v]==0)
            {
                maax = arr[v];
                vv = v;
            }
        }
        if(vv!=-1)
        {
            q.push(vv);
            color[vv] = 1;
        }
    }
}

int main()
{
    FAST

    int t;
    cin>>t;

    int cnt = 0;
    while(t--)
    {
        cnt++;
        last = 0;
        sum = 0;
        for(int i=0;i<=100;i++)
        {
            color[i] = 0;
            V[i].clear();
            arr[i] = 0;
        }
        int n, m;
        cin>>n>>m;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(int i=0;i<m;i++)
        {
            int u , v;
            cin>>u>>v;

            V[u].push_back(v);
        }

        BFS(0);
        cout<<"Case "<<cnt<<": "<<sum<<" "<<last<<endl;

    }

    return 0;
}

