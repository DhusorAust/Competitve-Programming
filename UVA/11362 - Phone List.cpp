
#include<bits/stdc++.h>
using namespace std;

bool consistent = true;

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

    bool ok = true;
    bool prob2 = true;

    for (int i = 0; i < len; i++) {
        int id = str[i] - '0';

        bool prob1  = false;


        if (curr->next[id] == NULL)
        {
            prob2 = false;
            curr->next[id] = new node();
            if(curr->endmark)
                prob1 = true;
        }
        curr = curr->next[id];
        if(prob1)
            ok = false;
    }
    if(prob2)
        ok = false;

    curr->endmark = true;

    if(!ok)
        consistent = false;
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

    int t;
    cin>>t;

    while(t--)
    {
        consistent = true;
        root  = new node();

        int n;
        cin>>n;

        while(n--)
        {
            string s;
            cin>>s;
            Insert(s,s.size());
        }

        if(consistent)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        del(root);

    }


    return 0;
}
