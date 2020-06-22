#include<bits/stdc++.h>
using namespace std;
int N,M;
string arr[100][100];
int cnt = 0;
string s1;
bool src(string s)
{
    for(int i=0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            if(arr[i][j]==s)
                return true;
        }
    }

    return false;
}
bool bol = false;
void f(string s,string sofar)
{
    int n = s.length();
    int i = 0;
    int l = 0;
    for(int j = n-1;j>=i;j--,l++)
    {
        string temp;
        string srch;
        for(int k=i;k<=j;k++)
        {
           temp.push_back(s[k]);
        }
        for(int k=j+1;k<n;k++)
        {
           srch.push_back(s[k]);
        }
        if(src(temp))
        {
            sofar+=temp;
            f(srch,sofar);
        }
        if(sofar==s1)
            bol = true;
    }
}
int main ()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>arr[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        bol = false;
        cin>>s;
        s1 = s;
        f(s,"");
       if( bol)
             cout<<"yes"<<endl;
       else
        cout<<"no"<<endl;
    }
    return 0;
}
/*
4 4
oy ni ta n
si l fat ri
ik sha na Xy
ba cr zz Ni
7
Niloy
rifat
tasin
shabana
ikramul
cristiano
ronaldo
*/

