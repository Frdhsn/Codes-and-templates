#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX=2e5+10,MOD=1e9+7;
 
int LIS(vector<int>A){
    vector<int>B;
    B.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        auto it = lower_bound(B.begin(),B.end(),A[i])-B.begin(); // increasing
        //auto it = upper_bound(B.begin(),B.end(),A[i])-B.begin(); // Non-Decresing
        if(it>=B.size()){
            B.push_back(A[i]);
        }
        else B[it]=A[i];
    }
    return B.size();
}
int main() {
    //memset(dp,-1,sizeof dp);
 
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)cin>>A[i];
	cout<<LIS(A)<<endl;
	return 0;
}
