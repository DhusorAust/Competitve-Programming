
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

int cnt = 0;
vector<string> v;

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


void print(node* curr,string& str, int id, string& s)
{
    if(cnt>=3)
        return;

    if(curr->endmark)
    {
        cnt++;
        v.push_back(s);
    }

   for(int i=0;i<26;i++)
   {
       if(curr->next[i]!=NULL)
       {
            char c = i+'a';
            string s2 = s;
            s2.push_back(c);
            print(curr->next[i],str,i,s2);
       }
   }
}

bool Search(string& str, int len)
{
    node* curr = root;
    int ID;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
        ID = id;
    }
    string s;
    print(curr,str,ID,str);
    return curr->endmark;
}


void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

 vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

     vector<vector<string>> ans;
     root  = new node();
     for(int i=0;i<products.size();i++)
     {
         Insert(products[i],products[i].size());
     }
     string s;
     for(int i=0;i<searchWord.size();i++)
     {
         s.push_back(searchWord[i]);
         cnt = 0;
         v.clear();
         Search(s,s.size());
         ans.push_back(v);
     }

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


