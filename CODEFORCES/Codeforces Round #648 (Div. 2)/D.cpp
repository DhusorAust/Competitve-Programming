#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

int color[100][100];
int X[4] = {0,0,+1,-1};
int Y[4] = {+1,-1,0,0};
int n,m;
string s[100],s2[100];
void DFS(int I,int J)
{

    color[I][J] = 1;
 
    for(int i=0;i<4;i++)
    {
        int vI, vJ;
        vI = I+ X[i];
        vJ = J + Y[i];

        if(vI>=0 && vI<n && vJ>=0 && vJ<m && (s[vI][vJ]=='.' || s[vI][vJ]=='G') && color[vI][vJ]==0)
            DFS(vI,vJ);
    }
    color[I][J] = 2;
}



int main()
{
    FAST
    int t;
    cin>>t;

    while(t--)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                color[i][j] = 0;
            }
        }

        cin>>n>>m;
        for(int i = 0;i<n;i++)
        {
            cin>>s[i];
            s2[i] = s[i];
        }

        int cnt = 0;
        int I =-1,J =-1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(s[i][j]=='G')
                {
                    cnt++;
                    I = i;
                    J = j;
                }
            }
        }

        if(I==-1 && J ==-1)
        {
            if(s[n-1][m-1]!='B' )
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

            continue;
        }

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(s2[i][j] =='B')
                {
                 
                    for(int k = 0;k<4;k++)
                    {
                        int vI, vJ;

                        vI = i+X[k];
                        vJ = j+Y[k];
                    
                        if(vI>=0 && vI<n && vJ>=0 && vJ<m)
                            s[vI][vJ] = '#';
                    }
                }
            }
        }

        DFS(I,J);
      
        if(color[n-1][m-1]!=2)
        {
            cout<<"No"<<endl;
            continue;
        }

        int cnt2 = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
               
                if(color[i][j] ==2 && s[i][j]=='G')
                {
                   cnt2++;
                }

            }
        }
        if(cnt2==cnt)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}


