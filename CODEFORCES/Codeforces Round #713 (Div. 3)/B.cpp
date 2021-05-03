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


int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        char arr[n][n];
        int i1 = -1;
        int j1 = -1;
        int i2 = -1;
        int j2 = -1;
        for(ll i = 0;i<n;i++)
        {
            for(ll j = 0; j<n;j++)
            {
                cin>>arr[i][j];
                if( (arr[i][j] == '*') && (i1 == -1) && (j1 == -1) )
                {
                    i1 = i;
                    j1 = j;
                }
                else if(arr[i][j]=='*')
                {
                    i2 = i;
                    j2 = j;
                }

            }
        }
        int I1,J1,I2,J2;
        if(i1==i2)
        {
            if(i1+1<n)
            {
                I1 = i1+1;
                J1 = j1;
                I2 = i2+1;
                J2 = j2;
            }
            else
            {
                I1 = i1-1;
                J1 = j1;
                I2 = i2-1;
                J2 = j2;
            }
        }
        else if(j1==j2)
        {
            if(j1+1<n)
            {
                I1 = i1;
                J1 = j1+1;
                I2 = i2;
                J2 = j2+1;
            }
            else
            {
                I1 = i1;
                J1 = j1-1;
                I2 = i2;
                J2 = j2-1;
            }
        }
        else
        {
            I1 = i1;
            J1 = j2;
            I2 = i2;
            J2 = j1;
        }
        arr[I1][J1] = '*';
        arr[I2][J2] = '*';

        for(ll i = 0;i<n;i++)
        {
            for(ll j = 0; j<n;j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }



    }

    return 0;
}

/*

*/

