#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sc(x) scanf("%d",&x)
#define scL(x) scanf("%lld",&x)
int main (){
    int t;sc(t);
    for(int tc=1;tc<=t;tc++){
        int N;sc(N);
        ll mn = 1e18 , mx = -1;
        for(int i=0;i<N;i++){
                ll x;
                scL(x);
                mn = min(mn,x);
                mx = max(mx,x);
        }
        ll res = mn*mx;
        printf("Case %d: %lld\n",tc,res);
    }
    return 0;
}

