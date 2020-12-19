#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
bool bol = true;
struct node {
    bool endmark;
    node* next[10 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
} * root;
void Insert(string& str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        if(curr->endmark)
            bol = false;
    }
    curr->endmark = true;
    for(ll i = 0;i<10;i++)
    {
         if(curr->next[i] != NULL)
            bol = false;
    }
}

void del(node* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}
int main()
{
    FAST
    ll t;
    cin>>t;
    while(t--)
    {
        root  = new node();
        bol = true;
        ll n;
        cin>>n;
        while(n--)
        {
            string s;
            cin>>s;
            Insert(s,s.size());
        }
        if(bol)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        del(root);
    }
    return 0;
}

