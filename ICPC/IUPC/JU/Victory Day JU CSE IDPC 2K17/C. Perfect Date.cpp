/*
  special case:
  
  3/3/2000
  3/3/2000
  same
  
  3/12/2000
  3/12/2000
  not sure
*/
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
int main() {
	int t;sc(t);
	
	for(int tc=1;tc<=t;tc++){
		int d1,m1,y1,d2,m2,y2;
		scanf("%d/%d/%d",&d1,&m1,&y1);
		scanf("%d/%d/%d",&d2,&m2,&y2);
		int mn1 = min(m1,d1);
		int mx1 = max(m1,d1);
		int mn2 = min(m2,d2);
		int mx2 = max(m2,d2);
		if(y1==y2 && ( mn1==mn2 && mx2==mx1)){
			if(mx1>12 || mx2>12 || (mn1==mx1 && mx2==mn2) )cout<<"Same\n";
			else cout<<"Not Sure\n";
		}
		else cout<<"Different\n";
	}
	return 0;
}
