#include<bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x);
#define scL(x) scanf("%lld",&x);
typedef long long int ll;
const int MAX=1e7+10;
bool mark[MAX];
ll phi[MAX],PrefixSum[MAX];
void gen()
{
    for(int i=1;i<MAX;i++)phi[i]=i;
    for(int i=2;i<MAX;i++){
        if(mark[i]==0){
            for(int j=i;j<MAX;j+=i)
                {mark[j]=1;phi[j]=phi[j]/i;phi[j]=phi[j]*(i-1);}
        }
    }
    for(int i=1;i<MAX;i++)PrefixSum[i]=PrefixSum[i-1]+phi[i];
}
ll solve(ll n,ll p)
{
    ll lo = 1 , hi = n;
    while(hi-lo>5){
        ll md = (lo+hi)/2LL;
        ll cnt = n/md;
        if(PrefixSum[cnt] < p){
            hi = md - 1;
        }
        else lo=md;
    }
    ll res = -1;
    for(ll st = max(lo-100,1LL);st<=min(hi+100,n);st++){
        ll cnt = n/st;
        if(PrefixSum[cnt]>=p)res = max(res,st);
    }
    return res;
}
int main ()
{
    gen();
    int t;sc(t);
    for(int tc=1;tc<=t;tc++){
            ll n,p;scL(n);scL(p);
            ll res = solve(n,p);
            printf("Case %d: %lld\n",tc,res);
    }
    return 0;
}
