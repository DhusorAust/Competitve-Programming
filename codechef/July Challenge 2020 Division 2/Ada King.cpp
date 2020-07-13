
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

       char arr[8][8];

       int k;
       cin>>k;

       for(int i=0;i<8;i++)
       {
           for(int j = 0;j<8;j++)
           {
               arr[i][j] = 'X';
           }
       }

       arr[0][0] = 'O';

       k--;
       for(int i=0;i<8;i++)
       {
           if(k==0)
                break;
           for(int j = 0;j<8;j++)
           {
               if(k==0)
                   break;
               if(i==0 && j==0)
                   continue;
               arr[i][j] = '.';
               k--;
           }
       }

       for(int i=0;i<8;i++)
       {
           for(int j = 0;j<8;j++)
           {
               cout<<arr[i][j];
           }
           cout<<endl;
       }

    }

    return 0;
}

