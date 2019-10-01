#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderedSet=
tree<T ,null_type , less<T>,
rb_tree_tag , tree_order_statistics_node_update>;
int main ()
{
    int N , K ;
    cin >> N >> K;
    orderedSet<int>S;
    for(int i=1;i<=N;i++){
        int x=i;//cin >> x;
        S.insert(x);
    }
    //vector<int>ans(N+1);
    int curr=0;
    while(!S.empty()){
            int sz = S.size();
            curr = (curr + K -1) % sz;
            auto it= S.find_by_order( curr);
            cout<< * ( it )<<" ";
            S.erase(it);
    }
    return 0;
}
