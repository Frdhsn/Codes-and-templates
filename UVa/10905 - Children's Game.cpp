#include<bits/stdc++.h>
using namespace std;
struct aw{
    string ss;
};
bool operator <(aw x,aw y)
{
    return x.ss+y.ss>y.ss+x.ss;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    int n,tmp,a,b;
    //ifstream ss("10905.txt");
    while((cin>>n) && n)
    {
        aw nyslagsa_appi[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>nyslagsa_appi[i].ss;
        }
        sort(nyslagsa_appi,nyslagsa_appi+n);
        for(int i=0;i<n;i++)
            cout<<nyslagsa_appi[i].ss;
        cout<<"\n";
    }
    return 0;
}
