#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
//priority_queue<int, vector<int>, greater<int> > min_q;
void inc1(int* i, int* j, ll n)
{
     *j+=2;
     if(*j>n)
        {
            *i = *i + 1;
            if(*i%2==0)
                *j = 2;
            else
                *j = 1;
        }
}
void inc2(int* i, int* j, ll n)
{
     *j+=2;
     if(*j>n)
        {
            *i = *i + 1;
            if(*i%2==0)
                *j = 1;
            else
                *j = 2;
        }
}
int main()
{
    FAST
    ll n;
    cin>>n;
    ll arr[n][n];
    int i1 = 1,j1 = 1,i2 =1,j2=2;
    for(ll i  = 1;i<=n*n;i++)
    {
        ll a;
        cin>>a;
        if(a==1)
        {
            if(i2<=n)
            {
                cout<<2<<" "<<i2<<" "<<j2<<endl<<flush;
                inc2(&i2,&j2,n);
            }
            else
            {
                cout<<3<<" "<<i1<<" "<<j1<<endl<<flush;
                inc1(&i1,&j1,n);
            }
        }
        else if(a==2)
        {
            if(i1<=n)
            {
                cout<<1<<" "<<i1<<" "<<j1<<endl<<flush;
                inc1(&i1,&j1,n);
            }
            else
            {
                cout<<3<<" "<<i2<<" "<<j2<<endl<<flush;
                inc2(&i2,&j2,n);
            }
        }
        else
        {
            if(i1<=n)
            {
                cout<<1<<" "<<i1<<" "<<j1<<endl<<flush;
                inc1(&i1,&j1,n);
            }
            else
            {
                cout<<2<<" "<<i2<<" "<<j2<<endl<<flush;
                inc2(&i2,&j2,n);
            }
        }
    }
    return 0;
}

