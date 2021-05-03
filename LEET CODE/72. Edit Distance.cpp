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
string s1, s2;
int dp[501][501];
int f(int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==n)
        return dp[i][j] = s2.size()-j;
    if(j==m)
        return dp[i][j] = s1.size()-i;
    if(s1[i]==s2[j])
        return dp[i][j] = f(i+1,j+1);
    return dp[i][j] = 1+min(min(f(i,j+1),f(i+1,j)),f(i+1,j+1));
}

 int minDistance(string word1, string word2) {
     s1 = word1;
     s2 = word2;
     memset(dp,-1,sizeof dp);
     return f(0,0);

    }


int main()
{
    FAST
    string s1, s2;
    cin>>s1>>s2;
    cout<<minDistance(s1, s2)<<endl;
    return 0;
}

