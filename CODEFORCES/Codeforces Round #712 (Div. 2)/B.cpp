
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
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
        ll arr[n+9];
        ll one[n+9];
        ll zero[n+9];
        memset(arr, 0, sizeof arr);
        memset(one, 0, sizeof one);
        memset(zero, 0, sizeof zero);
        string s1, s2;
        cin>>s1>>s2;
        s1 = "0"+s1;
        s2 = "0"+s2;
        for(ll i = 1;i<=n;i++)
        {
            if(s1[i]=='1')
                one[i] = 1;
            if(s1[i]=='0')
                zero[i] = 1;
        }
        for(ll i = 1;i<=n;i++)
        {
            one[i]+=one[i-1];
            zero[i]+=zero[i-1];
        }
        bool b = true;
        for(ll i = n;i>=1;i--)
        {
            if(s1[i]!=s2[i] && b && one[i]==zero[i])
            {
                arr[1]+=1;
                arr[i+1]-=1;
                b = false;
            }
            else if(s1[i]==s2[i] && !b && one[i]==zero[i])
            {
                arr[1]+=1;
                arr[i+1]-=1;
                b = true;
            }
        }
        for(ll i = 1;i<=n;i++)
        {
            arr[i]+=arr[i-1];
        }

        for(ll i = 1;i<=n;i++)
        {
            arr[i] =arr[i]%2;
        }
       /* cout<<endl;
        for(ll i = 1;i<=n;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;*/
        bool bl = true;
        for(ll i = 1;i<=n;i++)
        {
            if(s1[i]==s2[i] && arr[i]!=0)
            {
                bl = false;
                break;
            }

            if(s1[i]!=s2[i] && arr[i]!=1)
            {
                bl = false;
                break;
            }
        }

        if(bl)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;



    }

    return 0;
}


