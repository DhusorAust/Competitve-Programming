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

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n==0 || n==1)
        return n;
    int i = 0, j = 0;
    map<char, int> m;
    int ans = 1;
    for(;j<n;)
    {
        if(m[s[j]]==1)
        {
            m[s[i]]--;
            i++;
        }
        else
        {
            ans = max(ans,j-i+1);
            m[s[j]] = 1;
            j++;
        }
    }
    return ans;
}


int main()
{
    FAST
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}

