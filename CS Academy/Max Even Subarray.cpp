#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {

  ll n;
  cin>>n;
  ll arr[n], ans[n];

  for(int i=0;i<n;i++)
      cin>>arr[i];

  if(n==2)
  {
      cout<<arr[0]+arr[1]<<endl;
      return 0;
  }

  ans[n-1] = -100000000000;
  ans[n-2] = arr[n-1]+arr[n-2];
  ll ans2 = ans[n-2];

  for(int i = n-3;i>=0;i--)
  {
      ans[i] = arr[i]+arr[i+1];
      ans[i] = max(ans[i],ans[i]+ans[i+2]);
      ans2 = max(ans2,ans[i]);
  }

  cout<<ans2<<endl;
  return 0;
}
