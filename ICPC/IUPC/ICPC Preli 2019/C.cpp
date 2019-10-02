#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define sc(x) scanf("%d",&x)
#define scL(x) scanf("%lld",&x)
bool ok(int prev_sol , int prev_pen, int curr_sol, int curr_pen)
{
    if(curr_sol>prev_sol)return 1;
    if(curr_sol<prev_sol)return 0;
    if(curr_pen<=prev_pen)return 1; // -_-
    return 0;
}
int main (){
    int t;sc(t);
    for(int tc=1;tc<=t;tc++){
        int N;sc(N);
        vector<int>V[N+5];
        int solved[N+5],penalty[N+5];
        for(int i=0;i<N;i++){
                int id,pr,pen,y;
                sc(id);
                sc(pr);
                sc(pen);
                solved[id] = pr;
                penalty[id] = pen;
                sc(y);
                for(int j=0;j<y;j++){
                    int pn;sc(pn);
                    V[id].push_back(pn);
                }
        }
        int order[N+5];
        for(int i=0;i<N;i++)sc(order[i]);

        int prev_sol = solved[order[N-1]];
        int prev_pen = penalty[order[N-1]];

        bool possible = true;

        for(int i = N-2 ; i>=0 ; i--){
            int id = order[i];

            if(ok(prev_sol , prev_pen , solved[id], penalty[id])){
                prev_pen = penalty[id];
                prev_sol = solved[id];
            }
            else{
                int sz = V[id].size();
                int curr_sol = solved[id];
                int curr_pen = penalty[id];
                bool f = false;
                for(int j=0;j<sz;j++){
                    curr_sol++;
                    curr_pen+=V[id][j];
                    if(ok(prev_sol,prev_pen,curr_sol,curr_pen)){
                        prev_pen = curr_pen;
                        prev_sol = curr_sol;
                        f = true;break;
                    }
                }
                if(f==false){
                    possible=false;
                    break;
                }
            }
        }
        printf("Case %d: ",tc);
        if(possible==true)printf("We respect our judges :)\n");
        else printf("Say no to rumour >:\n");
    }
    return 0;
}


