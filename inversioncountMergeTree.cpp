#include<bits/stdc++.h>

using namespace std;

#define MAX 1000005

int n , Array[MAX+7] , Help[MAX + 7];
long long int cnt=0;

void Print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<Array[i]<<" ";
    }
}
void Merge(int l,int r)
{
    int i,j,mid,id=l;
    mid = (l+r)/2;
    i = l;
    j = mid + 1;

    while(i<=mid && j<=r)
    {
        if(Array[i]>Array[j])
        {
            Help[id++] = Array[j++];
            cnt+= (mid+1 - i);
        }
        else
        {
            Help[id++] = Array[i++];
        }
    }
    if(j<=r)
    {
        for(int k=j;k<=r;k++)
            Help[id++] = Array[k];
    }
    else{

        for(int k=i;k<=mid;k++)
            Help[id++] = Array[k];
    }
    for(int k=l;k<=r;k++) Array[k] = Help[k];

}
void Divide(int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        Divide(l,mid);
        Divide(mid+1,r);
        Merge(l,r);
    }
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        cin >> n;

        for(int i=1;i<=n;i++)
        {
            cin >> Array[i];
        }
        //cout<<"Before Sorting : ";
        //Print();

        Divide(1,n);

        //cout<<"\nAfter Sorting : ";
        //Print();
        cout<<cnt<<"\n";
    }
    return 0;
}
