#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)
//priority_queue<int, vector<int>, greater<int> > min_q;
struct node
{
    ll v,i,j;
};
bool cmp1(node a, node b)
{
    return a.v<b.v;
}

int main()
{
    FAST

    ll t;
    cin>>t;

    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll arr[n][m],arr2[n][m];
        vector<node> v;
        for(ll i = 0;i<n;i++)
        {
            for(ll j = 0;j<m;j++)
            {
                ll x;
                cin>>x;
                arr[i][j] = x;
                arr2[i][j] = -1;
                node A;
                A.i = i;
                A.j = j;
                A.v = x;
                v.push_back(A);
            }
        }
        sort(v.begin(),v.end(),cmp1);

        for(ll i = 0;i<m;i++)
        {
            arr2[v[i].i][i] = v[i].v;
        }

        /*for(ll i = 0;i<n;i++)
        {
            for(ll j = 0;j<m;j++)
            {
                cout<<arr2[i][j]<<" ";
            }
            cout<<endl;
        }*/

        for(ll i = m;i<v.size();i++)
        {
            for(ll j = 0;j<m;j++)
            {
                if(arr2[v[i].i][j]==-1)
                {
                    arr2[v[i].i][j] = v[i].v;
                    break;
                }
            }
        }

        for(ll i = 0;i<n;i++)
        {
            for(ll j = 0;j<m;j++)
            {
                cout<<arr2[i][j]<<" ";
            }
            cout<<endl;
        }



    }


    return 0;
}


