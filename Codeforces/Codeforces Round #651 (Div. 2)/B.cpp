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
       int m;
       cin>>m;
       int n=2*m;

       int arr[n];
       vector<int> v1,v2;
       for(int i=0;i<n;i++)
       {
          cin>>arr[i];
          if(arr[i]%2==0)
            v1.push_back(i+1);
          else
            v2.push_back(i+1);
       }
       int A = (n-2)/2;
       int cnt = 0;
       for(int i=1;i<v1.size();i+=2)
       {
           if(cnt==A)
            break;
           cout<<v1[i-1]<<" "<<v1[i]<<endl;
           cnt++;
       }

       for(int i=1;i<v2.size();i+=2)
       {
           if(cnt==A)
            break;
           cout<<v2[i-1]<<" "<<v2[i]<<endl;
           cnt++;
       }
    }
    return 0;
}

