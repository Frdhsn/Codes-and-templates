#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,k;cin >> n >> k;
    vector<int>V(n);
    for(int i=0;i<n;i++){
            cin >> V[i];
    }
    deque<int>DQ;
    for(int i=0;i<k;i++){
        while(!DQ.empty() && V[DQ.back()]<=V[i]){
                DQ.pop_back();
        }
        DQ.push_back(i);
    }
    for(int i=k;i<n;i++){
        cout<<V[DQ.front()]<<' ';
        // removing elements that are out of this window
        while(!DQ.empty() && DQ.front()<=i-k){
            DQ.pop_front();
        }
        // removing elements that are smaller than this element V[i]

        while(!DQ.empty() && V[DQ.back()]<=V[i]){
                DQ.pop_back();
        }
        DQ.push_back(i);
    }
    cout<<V[DQ.front()]<<endl;
    return 0;
}
