#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
//priority_queue<int, vector<int>, greater<int> > min_q;

struct node
{
    int a,b,c,d;
};
int main()
{
    FAST

    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        node arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d;
        }

        if(m%2!=0)
            {
                cout<<"NO"<<endl;
            }
        else
        {
            bool bol =false;
            for(int i=0;i<n;i++)
            {
                if(arr[i].b==arr[i].c)
                {
                    bol = true;
                    break;
                }
            }

            if(bol)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }


    }

    return 0;
}

