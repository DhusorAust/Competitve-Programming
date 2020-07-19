#include<bits/stdc++.h>
using namespace std;

int const N = 200009;
vector <int> V[N],ans;
int color[N];

bool cycle = false;

void DFS(int u)
{
    color[u] = 1;
    for(int i=V[u].size()-1;i>=0;i--)
    {
        int v = V[u][i];
        if(color[v]==0)
            DFS(v);
        else if(color[v]==1)
            cycle = true;
    }
    color[u] = 2;
    ans.push_back(u);
}

void topologicalSort(int n)
{
    ans.clear();
    for(int i=n;i>=1;i--)
    {
        if(color[i]==0)
            DFS(i);
    }
    reverse(ans.begin(),ans.end());
}

int main()

{

    int t;
    cin>>t;

    while(t--)
    {
        int n,E;
        cin>>n>>E;

        for(int i=0;i<=n;i++)
        {
            V[i].clear();
            color[i] = 0;
        }

        cycle = false;

        vector< pair< int, pair<int,int> > > Vect;
        for(int i=0;i<E;i++)
        {
            int a, u,v;
            cin>>a>>u>>v;

            if(a==1)
            {
                V[u].push_back(v);
                Vect.push_back(make_pair(1,make_pair(u,v)));
            }
            else
            {
                Vect.push_back(make_pair(0,make_pair(u,v)));
            }
        }

        topologicalSort(n);

        if(cycle)
        {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;

        int m[n+1];
        for(int i=0;i<n;i++)
        {
            m[ans[i]] = i;
        }

        for(int i=0;i<Vect.size();i++)
        {
            if(Vect[i].first ==1)
            {
                cout<<Vect[i].second.first<<" "<<Vect[i].second.second<<endl;
            }
            else
            {
                if(m[Vect[i].second.first]>m[Vect[i].second.second])
                {
                    cout<<Vect[i].second.second<<" "<<Vect[i].second.first<<endl;
                }
                else
                {
                    cout<<Vect[i].second.first<<" "<<Vect[i].second.second<<endl;
                }
            }
        }
    }
    return 0;
}


