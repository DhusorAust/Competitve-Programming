#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
};
int main()
{
    int n;
    cin>>n;
    vector<node> v;
    for(int i=0;i<n+2;i++)
    {
        node a;
        a.x = i;
        a.y = i;
        v.push_back(a);
    }
    for(int i=0;i<n-1+2;i++)
    {
        node a;
        a.x = v[i].x+1;
        a.y = v[i].y;
        v.push_back(a);

        a.x = v[i].x;
        a.y = v[i].y+1;
        v.push_back(a);
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i].x<<" "<<v[i].y<<endl;
    return 0;
}
