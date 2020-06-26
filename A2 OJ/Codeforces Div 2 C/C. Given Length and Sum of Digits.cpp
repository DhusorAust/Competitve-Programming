#include<bits/stdc++.h>
using namespace std;

int main()
{

    int m,s;
    cin>>m>>s;
    int arr[m];
    arr[0] = 1;
    for(int i=1;i<m;i++)
    {
        arr[i] = 0;
    }
    int sum = 1;
    int tmp = s/m;
    if(s%m!=0)
        tmp++;
    if(tmp>9 || (s==0 && m!=1))
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }

    for(int i=m-1;i>=1;i--)
    {
       if(sum==s)
        break;
       int req = s-sum;
       req = min(req,9);
       arr[i] = req;
       sum+=arr[i];
    }
    arr[0] += s-sum;

    for(int i=0;i<m;i++)
        cout<<arr[i];
    cout<<" ";

    for(int i=0;i<m;i++)
    {
        arr[i] = 0;
    }
    sum = 0;

    for(int i=0;i<m;i++)
    {
       if(sum==s)
           break;
       int req = s-sum;
       req = min(req,9);
       arr[i] = req;
       sum+=arr[i];
    }


    for(int i=0;i<m;i++)
        cout<<arr[i];
    cout<<endl;















    return 0;
}

