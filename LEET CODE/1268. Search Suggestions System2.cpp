

#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;

 vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

     vector<vector<string>> ans;

     sort(products.begin(),products.end());

     string s;

     for(int i=0;i<searchWord.size();i++)
     {
         s.push_back(searchWord[i]);

         vector<string> v;

         for(int j = 0;j<products.size();j++)
         {
             if(v.size()>=3)
                break;

             if(products[j].size()<s.size())
                continue;

             bool bol = true;

             for(int k = 0;k<s.size();k++)
             {
                 if(s[k]!=products[j][k])
                 {
                     bol = false;
                     break;
                 }
             }

             if(bol)
                v.push_back(products[j]);

         }

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


