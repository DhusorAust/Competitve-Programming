#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {

        ll n,m;
        cin>>n>>m;

        ll arr[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
            }
        }

        ll sum = 0;
        for(int i = 0;i<n/2;i++)
        {
            for(int j= 0 ;j <m/2;j++)
            {
                ll a = -1,b = -1,c = -1,d = -1,A,B,C,D;

                //ll arr2[4];


                a = arr[i][j];

                b = arr[n-i-1][m-j-1];

                c = arr[n-i-1][j];

                d = arr[i][m-j-1];

               // cout<<i<<j<<" "<<n-i-1<<m-j-1<<" "<<n-i-1<<j<<" "<<i<<m-j-1<<endl;
              //  cout<<a<<" "<<b<<" "<<c<<" "<<d;
                A = abs(a-b)+abs(a-c)+abs(a-d);
                B = abs(b-a)+abs(b-c)+abs(b-d);
                C = abs(c-b)+abs(c-a)+abs(c-d);
                D = abs(d-b)+abs(d-c)+abs(d-a);

                 if(A<=B && A<=C && A<=D )
                 {
                     sum+=A;
                     arr[n-i-1][m-j-1] =a;;
                     arr[n-i-1][j] = a;
                     arr[i][m-j-1] = a;


                 }
                 else if(B<=A && B<=C && B<=D )
                 {
                     sum+=B;
                     arr[i][j]  = b;
                     arr[n-i-1][j] = b;
                     arr[i][m-j-1] = b;
                 }
                  else if(C<=B && C<=A && C<=D )
                 {
                     sum+=C;
                     arr[i][j]  = c;
                     arr[n-i-1][m-j-1] = c;
                     arr[i][m-j-1] = c;
                 }
                  else if(D<=B && D<=C && D<=A )
                 {
                     sum+=D;
                     arr[i][j]  = d;
                     arr[n-i-1][m-j-1] = d;
                     arr[n-i-1][j] = d;
                 }



              // cout<<sum<<endl;




            }
        }

        if(n%2!=0)
        {

            int i = n/2;
            for(int j = 0,k=m-1;j<m/2;j++,k--)
            {
                sum+= abs(arr[i][j]-arr[i][k]);
            }

        }
        if(m%2!=0)
        {
            int j = m/2;
            for(int i = 0,k = n-1;i<n/2;i++,k--)
            {
                sum+= abs(arr[i][j]-arr[k][j]);
            }



        }

        cout<<sum<<endl;
    }

    return 0;
}

