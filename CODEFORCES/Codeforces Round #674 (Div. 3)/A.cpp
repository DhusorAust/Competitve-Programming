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

      int n,x;
      cin>>n>>x;

      if(n<=2)
        cout<<1<<endl;
      else
      {
          int cnt = 2;
          for(int i=3,j=1;i<=n;i++)
          {
                if(j>x)
                {
                    j = 1;
                    cnt++;
                }

                j++;
          }

          cout<<cnt<<endl;
      }

    }

    return 0;
}

