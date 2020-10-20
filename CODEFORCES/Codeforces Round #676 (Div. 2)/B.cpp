#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

struct node
{
    int x,y;
};

int main()
{
    FAST

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        vector<node> v;

        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }

        if(s[0][1]==s[1][0] && s[n-1][n-2]==s[n-2][n-1])
        {
            if(s[0][1]==s[n-1][n-2])
            {
                node A;
                A.x = 0+1;
                A.y = 1+1;
                v.push_back(A);

                A.x = 1+1;
                A.y = 0+1;
                v.push_back(A);

            }
        }
        else if(s[0][1]==s[1][0] && s[n-1][n-2]!=s[n-2][n-1])
        {
            if(s[n-1][n-2]==s[0][1])
            {
                node A;
                A.x = n-1+1;
                A.y = n-2+1;
                v.push_back(A);
            }
            else
            {     node A;
                  A.x = n-2+1;
                  A.y = n-1+1;
                  v.push_back(A);
            }
        }
        else if(s[0][1]!=s[1][0] && s[n-1][n-2]==s[n-2][n-1])
        {


            if(s[n-1][n-2]==s[0][1])
            {
                node A;
                A.x = 0+1;
                A.y = 1+1;
                v.push_back(A);
            }
            else
            {     node A;
                  A.x = 1+1;
                  A.y = 0+1;
                  v.push_back(A);
            }
        }
        else if(s[0][1]!=s[1][0] && s[n-1][n-2]!=s[n-2][n-1])
        {
            if(s[0][1]=='1')
            {
                node A;
                A.x = 0+1;
                A.y = 1+1;
                v.push_back(A);
            }
            else
            {
                node A;
                A.x = 1+1;
                A.y = 0+1;
                v.push_back(A);
            }

            if(s[n-1][n-2]=='0')
            {
                node A;
                A.x = n-1+1;
                A.y = n-2+1;
                v.push_back(A);
            }
            else
            {
                node A;
                A.x = n-2+1;
                A.y = n-1+1;
                v.push_back(A);
            }

        }

        cout<<v.size()<<endl;

        for(int i=0;i<v.size();i++)
        cout<<v[i].x<<" "<<v[i].y<<endl;







    }

    return 0;
}

