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

int longestValidParentheses(string s)
 {
    int cnt1 = 0;
    int cnt2 = 0;
    int n = s.size();
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i]=='(')
            cnt1++;
        else
            cnt2++;
        if(cnt2>cnt1)
        {
            cnt1 = 0;
            cnt2 = 0;
        }
        else if(cnt1==cnt2)
        {
            ans = max(ans, cnt1+cnt2);
        }
    }
    cnt1 = cnt2  = 0;
    for(int i = n-1;i>=0;i--)
    {
        if(s[i]==')')
            cnt1++;
        else
            cnt2++;
        if(cnt2>cnt1)
        {
            cnt1 = 0;
            cnt2 = 0;
        }
        else if(cnt1==cnt2)
        {
            ans = max(ans, cnt1+cnt2);
        }
    }
    return ans;
}


int main()
{
    FAST
    string s;
    cin>>s;
    cout<<longestValidParentheses(s) <<endl;

    return 0;
}

