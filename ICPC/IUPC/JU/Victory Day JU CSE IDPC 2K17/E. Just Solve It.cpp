#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ar[n+5];
        ll tn=0;
        ll to,fiv;
        to=fiv=0;
        for(int i=1;i<=n;i++)
        {
            cin>>ar[i];
            if(ar[i]%10==0) tn++;
            else if(ar[i]%5==0) fiv++;
            else if(ar[i]%2==0) to++;

        }
        long long int ans = tn*n-tn*(tn+1)/2 + to*fiv*1L;
        cout<<ans<<"\n";

    }
    return 0;
}
