//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>prefix , suffix;
        prefix.push_back(0);
        suffix.push_back(0);
        for(int i=0;i<cardPoints.size();i++){
            prefix.push_back(prefix[i] + cardPoints[i]);
        }
        for(int i=cardPoints.size()-1,j=0;i>=0;i--,j++){
            suffix.push_back(suffix[j] + cardPoints[i]);
        }
        int res=0,sum;
        for(int i=0;i<=k;i++){
            int x = i;
            int y = k-i;
            sum=prefix[x]+suffix[y];
            res=max(res,sum);
        }
        return res;
    }
};
