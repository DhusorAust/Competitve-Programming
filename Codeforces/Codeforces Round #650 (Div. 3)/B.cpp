#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int arr[n];
       int odd = 0, even = 0;
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           if(arr[i]%2==0)
              even++;
           else
              odd++;
       }
       bool bol = true ;
       if(n%2==0 && even!=odd)
          bol = false;
       else if(n%2!=0 && even-odd!=1)
          bol =false;
       else
       {
           int orr = 0, er = 0;
           for(int i=0;i<n;i++)
           {
               if(arr[i]%2==0 && i%2!=0)
               {
                   er++;
               }
           }
           cout<<er<<endl;
       }
       if(!bol)
        cout<<"-1"<<endl;
    }
    return 0;
}