#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

vector <int> V[60];
char arr[60][60];

void DFS(int u,int p)
{
    arr[p][u] = 'Y';
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        if(arr[p][v]=='N')
            DFS(v,p);
    }
}

int main()
{
    FAST

    int t;
    cin>>t;

    int cnt =  0;

    while(t--)
    {
        cnt++;
        int n;
        cin>>n;

        for(int i = 0;i<n;i++)
        {
            V[i].clear();
            for(int j = 0;j<n;j++)
            {
                arr[i][j] = 'N';
            }
        }
        string I,O;
        cin>>I>>O;

        for(int j = 0;j<n;j++)
        {
            int i = j+1;
            if(i<n)
            {
                if(O[i]=='Y' && I[j]=='Y')
                    V[i].push_back(j);
            }

            i = j-1;
            if(i>=0)
            {
                if(O[i]=='Y' && I[j]=='Y')
                    V[i].push_back(j);
            }
        }

        for(int i=0;i<n;i++)
        {
            DFS(i,i);
        }

        cout<<"Case #"<<cnt<<":"<<endl;

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<arr[i][j];

                      
            }
            cout<<endl;
        }
    }

    return 0;
}

