#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()

{
   double r,x,y,x1,y1;
   cin>>r>>x>>y>>x1>>y1;
   double R = 2*r;
   double dis = (x-x1)*(x-x1)+(y-y1)*(y-y1);
   dis = sqrt(dis);

   cout<<ceil(dis/R)<<endl;
   return 0;
}
