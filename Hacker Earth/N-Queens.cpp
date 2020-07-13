#include<bits/stdc++.h>

using namespace std;

int n;

int arr[20][20];

bool isSafe(int r, int c)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                if(i==r || c==j || i+j==r+c || i-j==r-c)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool f(int r)
{
    if(r==n)
        return true;

    for(int j=0;j<n;j++)
    {
        if(isSafe(r,j))
        {
            arr[r][j]=1;
            if(f(r+1))
                return true;
        }
        arr[r][j] = 0;
    }
    return false;
}


int main()
{
    cin>>n;

    if(f(0))
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
