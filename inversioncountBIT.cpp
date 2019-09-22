// BIT
// sum of the number of elements that are greater than current element after sorting decresingly 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
const int MAX=2e5 + 10;
ll BIT[MAX],N;
void update(int i,int x){
    for(;i<=N;i+=i&-i)BIT[i]+=x;
}
ll query(int i){
    ll res=0;
    for(;i>=1;i-=i&-i)res+=BIT[i];
    return res;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
            memset(BIT,0,sizeof BIT);
            vector<pii>V;
            int x;cin >> N;
            for(int i=0;i<N;i++){
                cin >> x;
                V.push_back({x,i+1});
            }
            sort(V.rbegin(),V.rend());
            ll res=0;
            for(int i=0;i<N;i++){
                int curr = V[i].first;
                int pos = V[i].second;
                res+=query(pos-1);
                update(pos,1);
            }
            cout<<res<<'\n';
    }
    return 0;
}
