#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=1e5 + 10,MOD=1000000007;
ll N,A[MAX],BIT[MAX];
ll query(int idx)
{
    int res=0;
    for(int i=idx;i>=1;i-=(i&-i)){
            res = (res%MOD + BIT[i]%MOD)%MOD;
    }
    return res%MOD;
}
void update(int idx,ll val)
{
    for(int i=idx;i<=N;i+=(i&-i)){
            BIT[i]=(BIT[i]%MOD + val%MOD)%MOD;
    }
}
void printBIT()
{
    printf("current state of BIT:\n");
    for(int i=1;i<=N;i++){
                printf("%d ",BIT[i]);
            }
    printf("\n");
}
int main ()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
            memset(BIT,0,sizeof BIT);
            scanf("%d",&N);
            vector< pair<ll,int> > V;
            for(int i=1;i<=N;i++)
            {
                scanf("%lld",&A[i]);
                V.push_back({A[i],i});
            }
            sort(V.begin(),V.end());
            ll ans=0,res=0,prev_val=-1e18,repeat=0;
            for(int i=0;i<N;i++)
            {
                    ll curr_idx = V[i].second;
                    ll curr_val = V[i].first;
                    res = 1 + query(curr_idx-1);
                    res%=MOD;
                    if(prev_val==curr_val)
                    {
                        res = res - repeat;
                        repeat = (repeat%MOD + res%MOD)%MOD;
                    }
                    else
                    {
                        prev_val = curr_val;
                        repeat = res;
                    }
                    update(curr_idx,res);
                    ans = (ans%MOD + res%MOD )%MOD;
                    //printBIT();
            }
            printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}
