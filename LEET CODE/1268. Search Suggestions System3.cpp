
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;


void Insert(string& str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}

int Search(string& str, int len)
{
    node* curr = root;
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return cnt;
        cnt++;
        curr = curr->next[id];
    }
    return cnt;
}


 vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

     vector<vector<string>> ans;
     sort(products.begin(),products.end());
     root  = new node();
     Insert(searchWord,searchWord.size());
     vector<string> v[searchWord.size()];
     for(int i=0;i<products.size();i++)
     {
         int cnt = Search(products[i],products[i].size());
         for(int j=0;j<cnt;j++)
         {
             if(v[j].size()<3)
                v[j].push_back(products[i]);
         }
     }
     for(int i=0;i<searchWord.size();i++)
         ans.push_back(v[i]);
     return ans;
}

int main()
{
    FAST

    int n;
    cin>>n;
    vector<string> products;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;

        products.push_back(s);

    }

    string searchWord;
    cin>>searchWord;

    vector<vector<string>> ans =  suggestedProducts( products, searchWord);

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
/*
5
mobile
mouse
moneypot
monitor
mousepad
mouse

*/

/*
1
havana
havana

*/

/*
5
bags
baggage
banner
box
cloths
bags
*/

/*
1
havana
tatiana

*/


