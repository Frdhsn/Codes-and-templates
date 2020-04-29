// problem link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
class Solution {
public:
    int maxScore(string s) {
        int total_zero = 0;
        for(int i=0;i<s.size();i++){
            total_zero+= (s[i]=='0');
        }
        int res=0,zero=0,one=0,le1=0;
        for(int i=0;i<s.size();i++){
            le1++;
            zero = zero + (s[i]=='0');
            one=0;
            int le2=0;
            for(int j=i+1;j<s.size();j++){
                one+=(s[j]=='1');
                le2++;
            }
            if( le1 && le2 )res=max(res,zero+one);
        }
        return res;
        
    }
};
