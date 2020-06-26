#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int arr[50][50],arr2[50][50];

        for(int i=1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                cin>>arr[i][j];
                arr2[i][j] = arr[i][j];
            }
        }

        if(n<m)
        {

            for(int i=1;i<=n;i++)
            {
                for(int j = 1;j<=m;j++)
                {
                    arr2[j][i]  = arr[i][j];
                }
            }
            swap(n,m);
        }
        int cnt = n+m-1;

        cnt/=2;

        bool bol = false;

        int ans = 0;

        for(int i=1,p = n;i<=cnt;i++,p--)
        {
            int zero = 0, one = 0;

            for(int j=i,k=1,q = p , r = m,cnt2 = 0;j>=1;j--,k++,q++,r--,cnt2++)
            {
                    if(arr2[j][k]!=0)
                        one++;
                    else
                        zero++;

                    if(arr2[q][r]!=0)
                        one++;
                    else
                        zero++;
                    if(cnt2==m-1)
                        break;
            }

            ans+=(min(one,zero));
        }

        cout<<ans<<endl;
    }
    return 0;
}
