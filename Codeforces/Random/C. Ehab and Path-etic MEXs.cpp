#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int E = n-1;
    vector< pair<int,int> > vc;
    map<int,int> m;
    int store = 0;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        vc.push_back(make_pair(u,v));
        m[u]++;
        m[v]++;
        if(m[u]>2)
            store = u;
        if(m[v]>2)
            store = v;
    }
    int fst = 0, lst = n-2;
    for(int i=0;i<vc.size();i++)
    {
        if(vc[i].first==store || vc[i].second==store)
            cout<<fst++<<endl;
        else
            cout<<lst--<<endl;
    }
}

